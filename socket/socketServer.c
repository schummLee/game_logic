#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "../components/game.h"

#define PORT 8080
#define BUFFER_SIZE (3 * 3 * sizeof(int))  // Assuming the matrix is of integer type

void startSocketServer() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int matrix[3][3];  // Buffer to store the 3x3 matrix

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 1) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    // Accept connections and receive matrix data
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Receive matrix data directly into the matrix buffer
        int bytes_received = recv(new_socket, matrix, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        }

        // Create a GameData instance
        GameData gameData;
        // Initialize other properties of gameData
        gameData.health = 100;  // For example

        // Copy the matrix buffer into the gameData
        memcpy(gameData.matrix, matrix, sizeof(matrix));

        // Call the playGame() function
        playGame(&gameData);

        // Send back the modified game data
        send(new_socket, &gameData, sizeof(GameData), 0);

        close(new_socket);
    }
}

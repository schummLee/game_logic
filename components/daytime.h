#ifndef DAYTIME_H
#define DAYTIME_H

typedef enum {
    MORNING,
    AFTERNOON,
    EVENING,
    NIGHT
} DayTime;

extern DayTime get_daytime(int hour);

#endif 

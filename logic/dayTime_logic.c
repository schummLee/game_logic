#include "../components/daytime.h"

Daytime get_daytime(int hour) {
    if (hour >= 6 && hour < 12) {
        return MORNING;
    } else if (hour >= 12 && hour < 18) {
        return AFTERNOON;
    } else if (hour >= 18 && hour < 22) {
        return EVENING;
    } else {
        return NIGHT;
    }
}

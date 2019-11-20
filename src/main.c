#include <stdio.h>
#include <unistd.h>

#include "util/timer.h"

int main() {
    printf("Testing timer.\n");

    for (unsigned int delay = 0; delay <= 5; delay++)
    {
        double start_time = get_time();
        printf("Sleeping for '%d' second(s).." , delay);
        sleep(delay);
        double stop_time = get_time();
        printf("delta: %lf\n", stop_time - start_time);
    }

    return 0;
}
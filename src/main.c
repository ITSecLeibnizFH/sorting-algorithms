#include <stdio.h>
#include <unistd.h>

#include "util/util.h"

int main() {
    printf("Testing timer.\n");

    double start_time = get_time();
    sleep(1);
    double stop_time = get_time();

    printf("delta: %lf\n", stop_time - start_time);

    return 0;
}
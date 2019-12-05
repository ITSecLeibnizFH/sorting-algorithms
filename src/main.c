#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "util/timer.h"
#include "algorithms.h"
#include "util/leibnizlib.h"

void print_state(const unsigned int length, const int *data) {
    if(is_sorted(length, data)) {
        printf("Data array is in order.\n");
    }
    else {
        printf("Data array is NOT in order.\n");
    }
}

int main() {
    
    printf("Leibniz-FH IT-Security 2019\n");
    printf("Sorting algorithms - speed comparison\n");
    printf("\n");

    printf("Showcasing timer accuracy..\n");
    for (unsigned int delay = 0; delay <= 3; delay++)
    {
        double start_time = get_time();
        printf("Sleeping for '%d' second(s).. " , delay);
        sleep(delay);
        double stop_time = get_time();
        printf("delta: %lf\n", stop_time - start_time);
    }

    const int length = 6;
    int* data = (int*) malloc(sizeof(int) * length);
    data[0] = 4;
    data[1] = 3;
    data[2] = 2;
    data[3] = 1;
    data[4] = 6;
    data[5] = 5;
    print_state(length, data);
    refimpl_aako_shakersort_int(length, data);
    print_state(length, data);

    for (int i = 0; i < 6; i++) {
        printf("%d\n", data[i]);
    }    

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "util/timer.h"
#include "algorithms.h"
#include "util/leibnizlib.h"

void print_state(const unsigned int length, const int* data) {
    if(is_sorted(length, data)) {
        printf("Data array is in order.\n");
    }
    else {
        printf("Data array is NOT in order.\n");
    }
}

void print_duration(double start, double stop) {
    double diff = stop - start;
    printf("Execution took %.3lf seconds.\n", diff);
}

int run_algorithm(algFuncPtr alg, const unsigned int length, int* data) {
    int bytes = sizeof(int) * length;
    int* data_lcopy = (int*) malloc(bytes);
    if(data_lcopy == NULL) {
        printf("Unable to allocate memory!\n");
        return 0;
    }
    memcpy(data_lcopy, data, bytes);

    double start_time = get_time();
    (*alg)(length, data_lcopy);
    double stop_time = get_time();

    print_state(length, data_lcopy);
    for (int i = 0; i < 6; i++) {
        printf("%d\n", data_lcopy[i]);
    }
    print_duration(start_time, stop_time);
    free(data_lcopy);
    return 1;
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
    if(data == NULL) {
        printf("Unable to allocate memory!\n");
        return EXIT_FAILURE;
    }
    data[0] = 4;
    data[1] = 3;
    data[2] = 2;
    data[3] = 1;
    data[4] = 6;
    data[5] = 5;

    run_algorithm(&refimpl_aako_shakersort_int, length, data);

    free(data);

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "util/timer.h"
#include "algorithms/reference/reference.h"
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
    printf("Execution took %.4lf seconds.\n", diff);
}

int run_algorithm(const struct sorting_algorithm alg, const unsigned int length, int* data) {
    printf("Running algorithm: %s\n", alg.a_name);
    printf(alg.a_desc);
    printf("\n");

    int bytes = sizeof(int) * length;
    int* data_lcopy = (int*) malloc(bytes);
    if(data_lcopy == NULL) {
        printf("Unable to allocate memory!\n");
        return 0;
    }
    memcpy(data_lcopy, data, bytes);

    double start_time = get_time();
    (alg.sort_func)(length, data_lcopy);
    double stop_time = get_time();

    print_state(length, data_lcopy);
    // for (int i = 0; i < length; i++) {
    //     printf("%d\n", data_lcopy[i]);
    // }
    print_duration(start_time, stop_time);
    free(data_lcopy);
    return 1;
}

int main() {    
    printf("Leibniz-FH IT-Security 2019\n");
    printf("Sorting algorithms - speed comparison\n");
    printf("\n");

    const int length = 10000;
    printf("Benchmarking with a test dataset of size: %d\n", length);

    int* data = (int*) malloc(sizeof(int) * length);
    if(data == NULL) {
        printf("Unable to allocate memory!\n");
        return EXIT_FAILURE;
    }
    
    if(readDataset(data, length) != EXIT_SUCCESS) {
        printf("No dataset specified, terminating..\n");
        exit(EXIT_FAILURE);
    }

    run_algorithm(REFERENCE, length, data);
    free(data);

    return EXIT_SUCCESS;
}
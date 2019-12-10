#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "util/timer.h"
#include "algorithms/reference/reference.h"
#include "util/leibnizlib.h"

void print_duration(double start, double stop) {
    double diff = stop - start;
    printf("Execution took %.4lf seconds.\n", diff);
}

int run_algorithm(const struct sorting_algorithm alg, const unsigned int length, int* data) {
    printf("Running algorithm: %s\n", alg.a_name);

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

    if(!is_sorted(length, data_lcopy)) {
        printf("Data array is NOT in order!\n");
        return EXIT_FAILURE;
    }
    print_duration(start_time, stop_time);
    printf("\n");

    free(data_lcopy);
    return EXIT_SUCCESS;
}

int main() {    
    printf("Leibniz-FH IT-Security 2019\n");
    printf("Sorting algorithms - speed comparison\n");
    printf("\n");

    const unsigned int sizes[] = {
        1000,
        10000,
        100000,
        0 // How do I terminate this correctly?
    };

    unsigned int* arrPtr = sizes;
    while(*arrPtr)
    {
        printf("------------------------------------------\n");
        printf("Benchmarking with a test dataset of size: %d\n\n", *arrPtr);

        int* data = (int*) malloc(sizeof(int) * *arrPtr);
        if(data == NULL) {
            printf("Unable to allocate memory!\n");
            return EXIT_FAILURE;
        }

        if(readDataset(data, *arrPtr) != EXIT_SUCCESS) {
            printf("No dataset specified, terminating..\n");
            exit(EXIT_FAILURE);
        }

        run_algorithm(REFERENCE, *arrPtr, data);
        free(data);

        arrPtr++;
    }
    
    return EXIT_SUCCESS;
}
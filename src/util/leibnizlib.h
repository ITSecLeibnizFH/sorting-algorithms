/* Author:      Jakob Schaffarczyk
 * Date:        22. Nov. 2019
 * Description: Library containing function,
 *              to read LeibnizFH dataset
 *              for benchmarking the sorting
 *              algorithms written in C.
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* LIMIT stores the length of the dataset
 * array stores an array:
 *     char arr[10] = {0};
 */

int readDataset(signed int *array, int LIMIT) {
    char fname[32];
    snprintf(fname, sizeof fname, "%s%d%s", "random_", LIMIT, ".txt");

    FILE *fp;
    fp = fopen(fname, "r");

    if (fp == NULL) {
        printf("Error reading file...\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < LIMIT; i++) {
        fscanf(fp, "%d", &array[i]);
    }

    return EXIT_SUCCESS;
}

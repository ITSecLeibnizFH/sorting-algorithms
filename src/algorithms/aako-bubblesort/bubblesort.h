#include "../algorithm.h"
#include "bubblesort.c"

const sorting_algorithm AAKO_BUBBLESORT = {
    &aako_bubblesort_int,
    "Bubblesort",
    "Basic bubblesort.",
    "Aaron Korte"
};

int aako_bubblesort_int(const unsigned int length, int *data);

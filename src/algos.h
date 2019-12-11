#include "algorithms/reference/reference.h"
#include "algorithms/aako-bubblesort/bubblesort.h"
#include "algorithms/algorithm.h"

sorting_algorithm* get_all() {
    static sorting_algorithm ptr[] = {
        // Reference implementation
        REFERENCE,

        // Add your algorithm here:
        AAKO_BUBBLESORT
        // ------------------------
    };

    return ptr;
}
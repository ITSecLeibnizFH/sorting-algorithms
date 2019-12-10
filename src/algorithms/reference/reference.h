#include "reference.c"
#include "../algorithm.h"

const struct sorting_algorithm REFERENCE = {
    &refimpl_aako_shakersort_int,
    "Shakersort (reference)",
    "Cocktail-/Shakersort default reference implementation.",
    "Aaron Korte"
};

int refimpl_aako_shakersort_int(const unsigned int length, int *data);

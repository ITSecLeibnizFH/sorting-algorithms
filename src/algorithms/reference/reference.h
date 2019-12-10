#include "reference.c"
#include "../../util/algorithms.h"

const struct sorting_algorithm REFERENCE = {
    &refimpl_aako_shakersort_int,
    "Shakersort (reference)",
    "Default Cocktail-/Shakersort reference implementation by Aaron Korte."
};

int refimpl_aako_shakersort_int(const unsigned int length, int *data);

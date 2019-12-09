#include "algorithms/reference/reference.h"

typedef int (*algFuncPtr)(const unsigned int length, int* data);

extern int refimpl_aako_shakersort_int(const unsigned int length, int* data);
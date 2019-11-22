#include "load_testdata.c"

// Load data from file into buffer. The return value of this function represents the length of the buffer plus a null terminator.
int generic_load(char *buf, const char *filename);
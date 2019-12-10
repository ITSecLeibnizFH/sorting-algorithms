typedef int (*algFuncPtr)(const unsigned int length, int* data);
typedef struct sorting_algorithm {
    algFuncPtr sort_func;
    // TODO: Make these dynamic length somehow?
    char a_name[64];
    char a_desc[512];
} sorting_algorithm;

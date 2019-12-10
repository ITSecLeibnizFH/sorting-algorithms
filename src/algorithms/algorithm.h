typedef int (*algFuncPtr)(const unsigned int length, int* data);
typedef struct sorting_algorithm {
    algFuncPtr sort_func;
    // TODO: Make these dynamic length somehow?
    char a_name[64]; // Algorithm name (e.g. "Shakersort")
    char a_desc[512]; // Additional information about the algorithm
    char a_author[64]; // Algorithm author's name
} sorting_algorithm;

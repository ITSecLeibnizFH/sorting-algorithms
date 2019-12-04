#include <stdio.h>

// Cocktail/Shaker-sort reference implementation
// Aaron Korte <github@aaronkorte.xyz>
// 20.11.2019 16:00

// TODO: Implement verbose logging.
void write_log(const char *msg) {
    #ifdef VERBOSE
    printf(msg);
    #endif
}

void swap(int *data, const unsigned int index1, const unsigned int index2) {
    int tmp = data[index1];
    data[index1] = data[index2];
    data[index2] = tmp;
}

int refimpl_aako_shakersort_int(const unsigned int length, int *data) {
    int swapped;
    do
    {
        swapped = 0;
        for (unsigned int i = 0; i < length - 2; i++)
        {
            if(data[i] > data[i+1]) {
                swap(data, i, i + 1);
                swapped = 1;
            }
        }
        if(!swapped) {
            break;
        }
        swapped = 0;
        for (unsigned int i = length - 2; i > 0; i--)
        {
            if(data[i] > data[i+1]) {
                swap(data, i, i + 1);
                swapped = 1;
            }
        }
    } while (swapped);    
}

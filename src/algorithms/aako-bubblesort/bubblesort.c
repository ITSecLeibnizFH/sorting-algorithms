/* Title:       Bubblesort
 * Author:      Aaron Korte <github@aaronkorte.xyz>
 * Date:        2019-12-10
 * Description: This is a super basic bubblesort.
 */

#include <stdlib.h>
#include <stdio.h>

#include "../../util/arrayops.h"

int aako_bubblesort_int(const unsigned int length, int *data)
{
    for (unsigned int bound = length - 1; bound > 1; bound--)
    {
        for (unsigned int i = 0; i < bound; i++)
        {
            if(data[i] > data[i+1])
                swap(data, i, i+1);
        }
    }

    return EXIT_SUCCESS;
}

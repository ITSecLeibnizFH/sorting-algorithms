#ifndef ARRAYOPS_H
#define ARRAYOPS_H

void swap(int *data, const unsigned int index1, const unsigned int index2) {
    int tmp = data[index1];
    data[index1] = data[index2];
    data[index2] = tmp;
}

#endif
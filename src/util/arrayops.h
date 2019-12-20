#ifndef ARRAYOPS_H
#define ARRAYOPS_H

void swap(int *data, const unsigned int index1, const unsigned int index2) {
    int tmp = data[index1];
    data[index1] = data[index2];
    data[index2] = tmp;
}

int is_sorted(const unsigned int length, const int *data) {
    for (unsigned int i = 1; i < length; i++) {
        if(data[i-1] > data[i]) {
            return 0;
        }
    }
    return 1;
}

#endif
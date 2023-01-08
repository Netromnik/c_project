#include "data_process.h"
#include "../data_libs/data_io.h"
#include <stdio.h>
#include <stdlib.h>
void main() {
    double *data;
    int n, err;
    err = input(&data, &n);
    if (err == 0) {
        if (normalization(data, n))
            output(data, n);
        else
            printf("ERROR");
    } else {
        printf("n/a");
    }
    if (err != 2)
        free(data);
}

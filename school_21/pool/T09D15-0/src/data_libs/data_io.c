#include "data_io.h"
#include <stdio.h>
#include <stdlib.h>

int input(double **data, int* n) {
    int err = 0;
    char c;
    int count = scanf("%d%c", n, &c);
    if (count ==2 && c == '\n' && *n > 0) {
        *data = malloc(*n * sizeof(double));
        for (double* p = *data; p - *data < *n; p++) {
            count = scanf("%lf%c", p, &c);
            if (count != 2 || (c == '\n' && p - *data != *n - 1) || (c == ' ' && p - *data == *n - 1))
                err = 1;
        }
    } else {
        err = 2;
    }
    return err;
}
void output(double* data, int n) {
    for (double* p = data; p - data< n; p++)
        printf("%.2lf ", *p);
    printf("\b");
}

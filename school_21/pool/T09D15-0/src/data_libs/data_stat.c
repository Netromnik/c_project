#include "data_stat.h"
#include <math.h>

double max(double *data, int n) {
    int max = *data;
    for (double *p = data; p - data < n; p++) {
        if (*p > max)
            max = *p;
    }
    return max;
}

double min(double *data, int n) {
    int min = *data;
    for (double *p = data; p - data < n; p++) {
        if (*p < min)
            min = *p;
    }
    return min;
}

double mean(double *data, int n) {
    double sum = 0;
    for (double *p = data; p - data < n; p++) {
        sum += *p;
    }
    sum /= n;
    return sum;
}

double variance(double *data, int n) {
    double m  = mean(data, n), m1 = 0;

    for (double *p = data; p - data < n; p++) {
       m1 += pow(*p - m, 2);
    }
    m1 /= n;
    return m1;
}

void sort(double **a, int n) {
    int tmp = 0;
    for (int i = 0; i < n; i ++) {
        for (double *p = *a+ 1; p - *a < n; p++) {
            if (*p < *(p - 1)) {
                tmp = *p;
                *p = *(p - 1);
                *(p - 1) = tmp;
            }
        }
    }
}


#include "decision.h"
#include <stdio.h>
#include "../data_libs/data_io.h"

int main() {
    double *data;
    int n;
    input(&data, &n);
    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");
    return 0;
}

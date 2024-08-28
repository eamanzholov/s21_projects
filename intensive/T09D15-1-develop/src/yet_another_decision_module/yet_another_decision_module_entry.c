#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    double *data;
    int n;

    if (scanf("%d", &n) != 1) {
        printf("n/a");
        exit(1);
    }

    data = malloc(n * sizeof(double));

    if (data == NULL) {
        printf("n/a");
        return 1;
    }

    input(data, n);

    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

    free(data);
    return 0;
}

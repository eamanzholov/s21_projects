#include <stdio.h>
#include <math.h>

double function(double x){
    return 7e-3 * pow(x, 4) + ((22.8 * cbrt(x) - 1e3) * x + 3) / (x * x / 2) - x * pow(10 + x, 2.0 / x) - 1.01; 
}
int main() {
    double x;
    if (scanf("%lf", &x) != 1) {
        printf("n/a\n");
        return 1;
    }
    double result = function(x);
    printf("%.1f\n", result);

    return 0;
}

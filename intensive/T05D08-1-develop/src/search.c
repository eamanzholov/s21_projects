#include <stdio.h>
#define NMAX 30

double mean(int *a, int n);
double variance(int *a, int n);
double customSqrt(double x);
int quest4(int *a, int n);
int input(int *a, int *n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 0) {
        printf("n/a");
        return 1;
    }

    int result = quest4(data, n);
    if (result != 0) {
        printf("%d", result);

    } else {
        printf("%d", 0);
    }
    return 0;
}
int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 1;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            return 1;
        }
    }
    return 0;
}

int quest4(int *a, int n) {
    double mean_val = mean(a, n);
    double variance_val = customSqrt(variance(a, n));
    for (int i = 0; i < n; i++) {
        if (a[i] != 0 && a[i] % 2 == 0 && a[i] >= mean_val && a[i] <= mean_val + 3 * variance_val) {
            return a[i];
        }
    }
    return 0;
}
double customSqrt(double x) {
    if (x == 0.0 || x == 1.0) {
        return x;
    }

    double epsilon = 1e-6;
    double guess = x / 2.0;
    while ((guess * guess - x) > epsilon) {
        guess = 0.5 * (guess + x / guess);
    }
    return guess;
}

double mean(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}
double variance(int *a, int n) {
    double mean_v = mean(a, n);
    double variance_v = 0;
    for (int i = 0; i < n; i++) {
        double diff = a[i] - mean_v;
        variance_v += diff * diff;
    }
    return variance_v / n;
}
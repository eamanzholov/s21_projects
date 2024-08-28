#include "data_stat.h"

#include <math.h>

double max(double *data, int n) {
    double max_val = data[0];
    for (int i = 1; i < n; ++i) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }
    return max_val;
}

double min(double *data, int n) {
    double min_val = data[0];
    for (int i = 1; i < n; ++i) {
        if (data[i] < min_val) {
            min_val = data[i];
        }
    }
    return min_val;
}

double mean(double *data, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += data[i];
    }
    return sum / n;
}

double variance(double *data, int n) {
    double mean_val = mean(data, n);
    double sum_squared_diff = 0.0;
    for (int i = 0; i < n; ++i) {
        sum_squared_diff += (data[i] - mean_val) * (data[i] - mean_val);
    }
    return sum_squared_diff / n;
}

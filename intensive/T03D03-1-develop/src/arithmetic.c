#include <stdio.h>


int main() {
    float a, b;
    if (scanf("%f %f", &a, &b) != 2 || (int)a != a || (int)b != b) {
        printf("n/a\n");
	return 1;
    }
    
    printf("%.0f ", a + b);
    printf("%.0f ", a - b);
    printf("%.0f ", a * b);
    
    if (b != 0) {
        printf("%.2f\n", a / b);
    } else {
        printf("n/a\n");
    }
    
    return 0;
}

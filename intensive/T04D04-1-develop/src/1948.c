#include <stdio.h>

int isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int largestPrimeDivisor(int num) {
    int largestDivisor = 2;

    for (int i = 2; i <= num; i++) {
        if (num % i == 0 && isPrime(i)) {
            largestDivisor = i;
        }
    }

    return largestDivisor;
}

int main() {
    // Ввод числа
    int num;
    scanf("%d", &num);

    int result = largestPrimeDivisor(num);
    printf("%d\n", result);

    return 0;
}

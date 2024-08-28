#include <stdio.h>

int a, b;

int max(int a, int b);

int main(){
    
    if (scanf("%d %d", &a, &b) != 2 || (int)a != a || (int)b != b) {
        printf("n/a\n");
        return 1;
    }
    if (a == b) {
        printf("both numbers are equal!");
        return 1;
    }
    printf("%d", max(a, b));
}

int max(int a, int b){
    return (a > b) ? a : b;
}

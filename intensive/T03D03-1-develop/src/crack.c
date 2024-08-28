#include <stdio.h>
 
double fun();
double x, y; 
int main() {
    
    if (scanf("%lf %lf", &x, &y) != 2) {
        printf("n/a\n");
        return 1;
    }

    double okr = 25.0;
    double result = fun();

    if(result < okr) {
        printf("GOTCHA");
        return 0;
    } else {
        printf("MISS");
        return 0;
    }
  
}

double fun(){
    return x * x + y * y;
}

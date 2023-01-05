#include <stdio.h>
#include <math.h>
#include <float.h>

long double function(long double x){
    return (x * (3 - x)) / powl(1 - x, (long double) 3);
}

int main(){
    const long double a = 0.0;
    const long double b = 0.5;

    int N;

    printf("Input N:");
    scanf_s("%d", &N);
    printf("N = %d\n", N);
    printf("Machine epsilon is equals to: %Lg\n\n", LDBL_EPSILON);
    printf("        Table of values of Taylor series and standard function\n");
    printf("___________________________________________________________________________\n");
    printf("|  x  | sum of Taylor series | f(x) function value | number of iterations |\n");
    printf("___________________________________________________________________________\n");

    long double step = (b - a) / (long double) N;
    long double taylor, sum;

    int iter = 0;

    for (long double x = a + step; x < b + step; x += step){
        for (int n = 0; n < 100; ++n) {
            taylor = n * (n + 2) * powl(x, (long double) n);
            sum += taylor;
            if (fabsl(sum - function(x)) < LDBL_EPSILON || iter > 100) {
                break;
            }
        }
        iter += 1;
        printf("|%.3Lf|%.20Lf|%.19Lf|           %d          |\n", x, sum, function(x), iter);
        sum = 0;
    }

    printf("___________________________________________________________________________\n");

    return 0;
}
#include <stdio.h>
#include <math.h>
#include <float.h>

long double function(long double x){
    return (0.1 * x * x) - (x * logbl(x));
}

long double first_derivative(long double x){
    return (0.2 * x) - logbl(x) - 1;
}

long double second_derivative(long double x){
    return 0.2 - (1 / x);
}

int check_convergence(long double a, long double b){
    long double step = (b - a) / 10000;
    for (long double x = a; x <= b; x += step){
        if (fabsl(function(x) * second_derivative(x)) < first_derivative(x) * first_derivative(x)){
           return 0;
        }
    }
    return 1;
}

long double find_x(long double x_0, long double x){
    while (fabsl(x - x_0) >= LDBL_EPSILON){
        printf("%Lf %Lf", x_0, x);
        x_0 = x;
        x = x_0 - function(x_0) / first_derivative(x_0);
    }
    return x;
}

int main() {
    long double a = 1;
    long double b = 2;

    long double x_0 = (a + b) / 2;
    long double x= x_0 - function(x_0) / first_derivative(x_0);

    if (check_convergence(a, b) == 1){
        printf("Method is convergent\n");
        printf("x = %Lf", find_x(x_0, x));
        printf("The value of the function for such x: %Lf", function(x));
    }
    else{
        printf("\nMethod doesn't convergent\n");
    }

    return 0;
}
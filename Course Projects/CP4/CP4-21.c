#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

long double function(long double x){
    return tanl(x) - ((1.0 / 3.0) * powl(tanl(x), 3)) + ((1.0 / 5.0) * powl(tanl(x), 5)) - (1.0 / 3);
}

int main(){
    long double a = 0;
    long double b = 0.8;

    printf("\nDichotomy Method");

    if (function(a) * function(b) > 0){
        printf("No roots on the segment");
        exit(0);
    }

    while (fabsl(a - b) > LDBL_EPSILON){
        if (function(a) * function((a + b) / 2) > 0){
            a = (a + b) / 2;
            b = b;
        }
        else if (function(b) * function((a + b) / 2) > 0){
            a = a;
            b = (a + b) / 2;
        }
    }

    printf("\nx = %Lf\n", (a + b) / 2);
    printf("The value of the function for such x: %Lf\n", function((a + b) / 2));

    return 0;
}
#include <stdio.h>

int main(){
    float a, b;
    float x, y;

    printf("Input the ends of the first segment:");
    scanf_s("%f %f", &a, &b);

    printf("Input the ends of the second segment:");
    scanf_s("%f %f", &x, &y);

    if ((a < x && x < b) || (a < y && y < b) || (x < a && a < y) || (x < b && b < y)){
        printf("Segments intersect");
    }
    else if (b < x || y < a){
        printf("Segments don't intersect");
    }

    return 0;
}
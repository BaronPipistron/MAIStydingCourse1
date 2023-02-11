#include <stdio.h>

int get_byte(int number, int n){
    return (number >> ((n - 1) * 8)) & 255;
}

int main(){
    int number, n;

    printf("Input the number:");
    scanf_s("%d", &number);

    printf("Input the number of byte:");
    scanf_s("%d", &n);

    printf("%d", get_byte(number, n));

    return 0;
}
#include <stdio.h>

int get_byte(int number, int n){
    return (number >> ((n - 1) * 8)) & 255;
}

void bin(int number){
    int count = 0;
    int array[8];

    while (number >= 1){
        if ((number % 2 == 1 && number > 1) || number == 1){
            array[count] = 1;
        }
        else{
            array[count] = 0;
        }
        number /= 2;
        count += 1;
    }
    for(int i = count; i != 8; ++i){
        printf("0");
    }
    for(int j = count - 1; j >= 0; j -= 1){
        printf("%d", array[j]);
    }
}

int main(){
    int number;

    printf("Input the number:");
    scanf_s("%d", &number);

    for(int i = 1; i <= 4; ++i){
        bin(get_byte(number, i));
        printf(" ");
    }

    return 0;
}

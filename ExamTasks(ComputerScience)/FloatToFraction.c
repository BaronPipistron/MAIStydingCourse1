#include <stdio.h>

int main(){
    int denominator = 1;
    int num, i = 0, flag = 0;
    char array[50];

    printf("Input the number:");

    while((num = getchar()) != '*'){
        if (flag == 0 && num >= '0' && num <= '9'){
            array[i] = (char) num;
            i += 1;
        }
        if (flag == 1 && num >= '0' && num <= '9'){
            array[i] = (char) num;
            denominator *= 10;
            i += 1;
        }
        else if(num == '.'){
            flag = 1;
        }
    }

    if (array[0] == '0'){
        for (int j = 1; j < i; ++j){
            printf("%c", array[j]);
        }
    }
    else{
        for (int j = 0; j < i; ++j){
            printf("%c", array[j]);
        }
    }

    printf(" / %d", denominator);

    return 0;
}
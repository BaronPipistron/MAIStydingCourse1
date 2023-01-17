#include <stdio.h>
#include <math.h>

int len_num(int num){
    int len = 0;
    while(num != 0){
        len += 1;
        num /= 10;
    }
    return len;
}

int main(){
    int num, flag = 1;

    printf("Input the number:");
    scanf_s("%d", &num);

    num = abs(num);

    int i = len_num(num) / 2;

    while(i != 0){
        if ((num % 10) == (num / (int) pow(10, len_num(num) - 1))){
            i -= 1;
            num = num % (int) pow(10, len_num(num) - 1);
            num = num / 10;
        }
        else{
            flag = 0;
            break;
        }
    }

    if (flag == 1){
        printf("This number is palindrome");
    }
    else{
        printf("This number isn't palindrome");
    }
    return 0;
}
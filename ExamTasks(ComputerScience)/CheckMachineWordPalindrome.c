#include <stdio.h>
#include <stdint.h>

int main(){
    uint64_t num;

    int flag = 0;

    printf("Input the number:");
    scanf_s("%lld", &num);

    for (int i = 0; i <= 32; ++i){
        if (((num >> i) & 1) == ((num >> (63 - i) & 1))){
            flag = 1;
        }
        else{
            flag = 0;
            break;
        }
    }

    if (flag == 1){
        printf("This machine word is palindrome");
    }
    else{
        printf("This machine word isn't palindrome");
    }

    return 0;
}

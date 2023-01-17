#include <stdio.h>
#include <math.h>

int get_len(int num){
    int len = 0;
    while (num != 0){
        len += 1;
        num /= 10;
    }
    return len;
}

int main(){
    int num;

    printf("Input the number:");
    scanf_s("%d", &num);

    int count = get_len(abs(num));

    if (num < 0){
        printf("-");
    }

    while (count != 0){
        printf("%d", abs(num) % 10);
        num /= 10;
        count -= 1;
    }

    return 0;
}

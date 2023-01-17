#include <stdio.h>
#include <math.h>

int get_len(int num){
    int len = 0;
    while(num != 0){
        num /= 10;
        len += 1;
    }
    return len;
}

int main(){
    int num, array[50], i = 0;

    printf("Input the number:");
    scanf_s("%d", &num);

    int num_1 = abs(num);
    int len = get_len(num_1);

    while (len != 0){
        array[i] = num_1 % 10;
        num_1 /= 10;
        i += 1;
        len -= 1;
    }

    if (num < 0){
        printf("-");
    }
    for(int j = 0; j < get_len(abs(num)); ++j){
        printf("%d", array[j]);
    }

    return 0;
}
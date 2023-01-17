#include <stdio.h>

int main(){
    int num = 1, count;

    while (num < 999){
        count = 0;
        for (int i = 1; i < num; ++i){
            if (num % i == 0){
                count += 1;
            }
        }

        if (count == 1){
            printf("%d ", num);
        }

        num += 1;
    }

    return 0;
}
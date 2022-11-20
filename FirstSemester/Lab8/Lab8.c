#include <stdio.h>

int main(){
    int massive_size, k = 0, digit, summa, min_len, count, max_summa;
    min_len = 999;
    max_summa = 0;
    printf("Input the number of numbers: ");
    scanf_s(" %d", &massive_size);
    int lst[30];
    while (k != massive_size){
        printf("Input the number: ");
        scanf_s(" %d", &digit);
        lst[k] = digit;
        k += 1;
    }
    for (int i = 0; i < massive_size; i++){
        summa = 0;
        count = 0;
        for (int j = i; j < massive_size; j++){
            summa += lst[j];
            count++;
            if (summa % 89 == 0){
                if (summa > max_summa || (summa == max_summa && count < min_len)){
                    max_summa = summa;
                    min_len = count;
                }
            }
        }
    }
    printf("Minimum length of subsequence: %d", min_len);
    return 0;
}
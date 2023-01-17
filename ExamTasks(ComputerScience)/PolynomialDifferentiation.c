#include <stdio.h>

int main(){
    int n, array[50];

    printf("Input the major degree of X:");
    scanf_s("%d", &n);

    printf("Input the coefficients front X(begin from major):");
    for(int i = 0; i <= n; ++i){
        scanf_s("%d", &array[i]);
    }

    int k = n;

    for (int j = 0; j < n; ++j){
        printf("%dx^%d", k * array[j], k - 1);

        if (j < n - 1){
            printf(" + ");
        }

        k -= 1;
    }

    return 0;
}
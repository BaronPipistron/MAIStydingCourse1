#include <stdio.h>

int matrix[100][100];

int sum_up(int i){
    int sum = 0;
    int j = i;
    while (j > 0){
        i += 1;
        j -= 1;
    }
    while (i >= 0){
        sum += matrix[i][j];
        i -= 1;
        j += 1;
    }
    return sum;
}

int main() {
    int n;
    printf("Input matrix size: ");
    scanf_s(" %d", &n);
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            scanf_s("%d", &matrix[i][j]);
        }
    }
    int i = 1;
    while (i < n - 1){
        int j = i;
        matrix[i][j] = sum_up(i);
        i += 1;
    }
    for (int a = 0; a < n; ++a){
        for (int b = 0; b < n; ++b){
            printf("%d%c", matrix[a][b], ' ');
        }
        printf("\n");
    }
    return 0;
}
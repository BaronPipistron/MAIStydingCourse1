#include <stdio.h>
#include <assert.h>

int matrix[100][100];

int abs(int x){
    return (x >= 0) ? x : -x;
}

void main_diagonal(int i, int j){
    while(i >= 0 && j >= 0){
        printf("%d ", matrix[i][j]);
        i -= 1;
        j -= 1;
    }
}

void up_diagonal(int i, int j, int count){
    while( i >= count / 2 && j >= 0){
        printf("%d ", matrix[i][j]);
        i -= 1;
        j -= 1;
    }
}

void down_diagonal(int i, int j, int n, int count){
    while (i <= abs(n - 1 - count) + 1 && j <= n - 1){
        printf("%d ", matrix[i][j]);
        i += 1;
        j += 1;
    }
}

void test_abs(){
    assert(abs(4) == 4);
    assert(abs(-19) == 19);
    assert(abs(85) == 85);
    assert(abs(-467) == 467);
    assert(abs(0) == 0);
}

int main(){
    test_abs();

    int n;
    printf("Input matrix size: ");
    scanf_s(" %d", &n);
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            scanf_s("%d", &matrix[i][j]);
        }
    }
    main_diagonal(n - 1, n - 1);
    int count = 1;
    for (int k = 1; k <= n - 2; ++k){
        down_diagonal(0, k, n, count);
        count += 1;
        up_diagonal(n - 1, n - k - 1, count);
        count += 1;
    }
    printf("%d %d", matrix[0][n - 1], matrix[n - 1][0]);
}
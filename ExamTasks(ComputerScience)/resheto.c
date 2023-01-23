// O(n log n)
#include <stdio.h>

int v[10001];

int main() {
    int n = 10000;
    // заполняем массив
    for(int i = 0; i <= n; i++)
        v[i] = i;
    // обработка
    for(int i = 2; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(v[j] == 0)
                continue;
            if(j % i == 0) {
                v[j] = 0;
                continue;
            }
        }
        if(i * i > n)
            break; // проверка на выход из массива
    }
    // вывод на печать
    int c = 0;
    for(int s=0; s <= n; s++) {
        if(v[s] != 0) {
            printf("%d\n", v[s]);
            c++;
        }
        if (c == 999)
            break;
    }
    return 0;
}

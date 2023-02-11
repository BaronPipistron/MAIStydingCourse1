#include <stdio.h>
#include <math.h>

int main(){
    double num;
    int a;

    printf("Input the number:");
    scanf_s("%lf", &num);
    printf("Input number of decimals:");
    scanf_s("%d", &a);

    printf("%x", (unsigned int) num);
    for(int i = 0; i < a; i++){
        num -= trunc(num);
        num *= 16;
        if ((int) num == 15){
            printf("F");
        }
        else if ((int) num == 14){
            printf("E");
        }
        else if ((int) num == 13){
            printf("D");
        }
        else if ((int) num == 12){
            printf("C");
        }
        else if ((int) num == 11){
            printf("B");
        }
        else if ((int) num == 10){
            printf("A");
        }
        else{
            printf("%d", (unsigned int) num);
        }
    }

    return 0;
}
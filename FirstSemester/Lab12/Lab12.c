#include <stdio.h>
#include <assert.h>

int power(int x, int y){
    int degree = x;
    while (y > 1){
        y -= 1;
        x = x * degree;
    }
    return x;
}

int number_of_digits(int x){
    int k = 0;
    while (x > 0){
        x = x / 10;
        k += 1;
    }
    return k;
}

int work_digit(int num){
    int k = number_of_digits(num);
    int new_num = num / power(10, k - 1) * power(10, k - 3) + num % 10;
    num = num % power(10, k - 2) / power(10, 2);
    new_num = new_num + num * 10;
    return new_num;
}

void test_power(){
    assert(power(2, 3) == 8);
    assert(power(10, 5) == 100000);
    assert(power(12, 2) == 144);
    assert(power(2, 9) == 512);
}

void test_number_of_digits(){
    assert(number_of_digits(123) == 3);
    assert(number_of_digits(5792291) == 7);
    assert(number_of_digits(123456789) == 9);
    assert(number_of_digits(5) == 1);
}

void test_work_digit(){
    assert(work_digit(23789) == 279);
    assert(work_digit(125478690) == 1547860);
    assert(work_digit(1478523) == 17853);
    assert(work_digit(125) == 15);
}

void all_tests(){
    test_power();
    test_number_of_digits();
    test_work_digit();
}

int main(){
    all_tests();

    int num;
    printf("Input the number: ");
    scanf_s("%d", &num);
    if (num > 0) {
        if (num / 10 == 0) {
            printf("This number hasn't second and penultimate digits");
        } else if (num / 100 == 0) {
            printf("New number: - ");
        } else {
            printf("New number: %d", work_digit(num));
        }
    }
    else{
        num = num * (-1);
        if (num / 10 == 0) {
            printf("This number hasn't second and penultimate digits");
        } else if (num / 100 == 0) {
            printf("New number: - ");
        } else {
            printf("New number: %d", work_digit(num) * (-1));
        }
    }
    return 0;
}
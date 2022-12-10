#include <stdio.h>
#include <assert.h>

char ascii_to_char(int symbol){
    if (symbol == 48){
        return '0';
    }
    else if (symbol == 49){
        return '1';
    }
    else if (symbol == 50){
        return '2';
    }
}

void print_char(int count, char array[50]){
    for (int k = 0; k < count; ++k){
        printf("%c", array[k]);
    }
}

void test_ascii_to_char(){
    assert(ascii_to_char(48) == '0');
    assert(ascii_to_char(49) == '1');
    assert(ascii_to_char(50) == '2');
}

int main(){
    test_ascii_to_char();

    int state = 1, count = 0, k = 0;
    int symbol;

    while((symbol = getchar()) != '*'){
        char array[50];
        switch (state) {
            case 1:
                if (symbol >= '0' && symbol <= '2'){
                    array[count] = ascii_to_char(symbol);
                    count += 1;
                    state = 2;
                }
                else if ((symbol >= '3' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')){
                    state = 5;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t'){
                    count = 0;
                    state = 1;
                }
                break;

            case 2:
                if (symbol == '0'){
                    array[count] = ascii_to_char(symbol);
                    count += 1;
                    state = 3;
                }
                else if (symbol >= '1' && symbol <= '2'){
                    array[count] = ascii_to_char(symbol);
                    count += 1;
                    state = 2;
                }
                else if ((symbol >= '3' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')){
                    state = 5;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t'){
                    count = 0;
                    state = 1;
                }
                break;

            case 3:
                if (symbol == '0'){
                    array[count] = ascii_to_char(symbol);
                    count += 1;
                    state = 3;
                }
                else if (symbol >= '1' && symbol <= '2'){
                    array[count] = ascii_to_char(symbol);
                    count += 1;
                    state = 2;
                }
                else if ((symbol >= '3' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')){
                    state = 5;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t'){
                    k += 1;
                    print_char(count, array);
                    printf("%c", ' ');
                    state = 4;
                }
                break;

            case 4:
                if (symbol == '0'){
                    count = 0;
                    array[count] = ascii_to_char(symbol);
                    count += 1;
                    state = 3;
                }
                else if (symbol >= '1' && symbol <= '2'){
                    count = 0;
                    array[count] = ascii_to_char(symbol);
                    count += 1;
                    state = 2;
                }
                else if ((symbol >= '3' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')){
                    count = 0;
                    state = 5;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t'){
                    count = 0;
                    state = 1;
                }
                break;

            case 5:
                if ((symbol >= '0' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')){
                    count = 0;
                    state = 5;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t'){
                    count = 0;
                    state = 1;
                }
                break;

            default:
                break;
        }
    }
    printf("\nSuitable numbers: %d", k);

    return 0;
}
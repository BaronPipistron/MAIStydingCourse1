#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <inttypes.h>

const uint64_t vowels = (
        1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') |
        1u << ('o' - 'a') | 1u << ('u' - 'a') | 1u << ('y' - 'a')
);

const uint64_t consonants = (
        1u << ('b' - 'a') | 1u << ('c' - 'a') | 1u << ('d' - 'a') | 1u << ('f' - 'a') | 1u << ('g' - 'a') |
        1u << ('h' - 'a') | 1u << ('j' - 'a') | 1u << ('k' - 'a') | 1u << ('l' - 'a') | 1u << ('m' - 'a') |
        1u << ('n' - 'a') | 1u << ('p' - 'a') | 1u << ('q' - 'a') | 1u << ('r' - 'a') | 1u << ('s' - 'a') |
        1u << ('t' - 'a') | 1u << ('v' - 'a') | 1u << ('w' - 'a') | 1u << ('x' - 'a') | 1u << ('z' - 'a')
);

const uint64_t numbers = (
        1u << ('0' - '0') | 1u << ('1' - '0') | 1u << ('2' - '0') | 1u << ('3' - '0') | 1u << ('4' - '0') |
        1u << ('5' - '0') | 1u << ('6' - '0') | 1u << ('7' - '0') | 1u << ('8' - '0') | 1u << ('9' - '0')
);

int is_vowels(char symbol) {
    uint64_t symbol_num = 1u << (symbol - 'a');
    if ((symbol_num & ~vowels) == 0){
        return 1;
    }
    return 0;
}

int is_consonants(char symbol) {
    uint64_t symbol_num = 1u << (symbol - 'a');
    if ((symbol_num & ~consonants) == 0){
        return 1;
    }
    return 0;
}

int is_numbers(char symbol) {
    uint64_t symbol_num = 1u << (symbol - '0');
    if ((symbol_num & ~numbers) == 0){
        return 1;
    }
    return 0;
}

int check_word_set(uint64_t word_set){
    uint64_t array[6] = {1u << ('a' - 'a'), 1u << ('e' - 'a'), 1u << ('i' - 'a'),
                         1u << ('o' - 'a'), 1u << ('u' - 'a'), 1u << ('y' - 'a')};

    char array_vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};

    int sum = 0;
    for(int i = 0; i < 5; ++i){
        if (array[i] == (word_set >> (array_vowels[i] - 'a'))){
            sum += 1;
        }
    }
    return sum;
}

void test_is_vowels(){
    assert(is_vowels('a') == 1);
    assert(is_vowels('i') == 1);
    assert(is_vowels('z') == 0);
    assert(is_vowels('x') == 0);
}

void  test_is_consonants(){
    assert(is_consonants('b') == 1);
    assert(is_consonants('v') == 1);
    assert(is_consonants('o') == 0);
    assert(is_consonants('e') == 0);
}

void test_is_numbers(){
    assert(is_numbers('1') == 1);
    assert(is_numbers('3') == 1);
    assert(is_numbers('b') == 0);
    assert(is_numbers('h') == 0);
}

void all_tests(){
    test_is_vowels();
    test_is_consonants();
    test_is_numbers();
}

int main(){
    all_tests();

    int symbol;
    int state = 1, count = 0, flag_1 = 0, flag_2 = 0;
    uint64_t word_set = 0;

    while ((symbol = tolower(getchar())) != '*'){
        switch (state) {
            case 1:
                if ((is_vowels((char)symbol) & vowels) == 1 && symbol != '5'){
                    word_set |= (1 << ((char)symbol - 'a'));
                    count += 1;
                    state = 1;
                }
                else if (((is_consonants((char)symbol) & consonants) == 1) || ((is_numbers((char)symbol) & numbers) == 1)){
                    state = 1;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t'){
                    if (check_word_set(word_set) == 1){
                        flag_1 += 1;
                    }
                    else if (check_word_set(word_set) > 1){
                        flag_2 -= 1;
                    }
                    if (count == 1 || (flag_1 != 0 && flag_2 == 0 && count > 0)){
                        printf("Yes, there is such a word");
                        exit(0);
                    }
                    word_set = 0;
                    count = 0;
                    state = 2;
                }
                break;

            case 2:
                flag_1 = 0;
                flag_2 = 0;
                if ((is_vowels((char)symbol) & vowels) == 1){
                    word_set |= (1 << ((char)symbol - 'a'));
                    count += 1;
                    state = 1;
                }
                else if (((is_consonants((char)symbol) & consonants) == 1) || ((is_numbers((char)symbol) & numbers) == 1)){
                    state = 1;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t'){
                    word_set = 0;
                    count = 0;
                    flag_1 = 0;
                    flag_2 = 0;
                    state = 2;
                }
                break;

            default:
                break;
        }
    }

    if (flag_1 == 0 || flag_2 < 0){
        printf("No, there is no such word");
    }

    return 0;
}
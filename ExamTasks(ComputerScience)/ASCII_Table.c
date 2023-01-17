#include <stdio.h>

int main(){
    printf("    ASCII Table\n");
    printf(" Symbol | Code \n");

    for (int i = 0; i <= 127; ++i){
        printf("   %c   |  %d  \n", i, i);
    }

    return 0;
}
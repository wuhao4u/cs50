#include <cs50.h>
#include <stdio.h>
#include <string.h>

void print_half_pyramid(int height);

int main(void) {
    do {
        printf("Height: ");
        h = get_int();
    } while(h < 0 || h > 23);

    print_half_pyramid(h);

    return 0;
}

void print_half_pyramid(int height) {
    int i,j,k;
    int sign, blanks;

    for(i = 0; i < height; ++i) {
        sign = i + 2;
        blanks = (height+1) - sign;
        
        for(j = 0; j < blanks; j++) {
            printf(" ");
        }
        for(k = 0; k < sign; k++) {
            printf("#");
        }
        printf("\n");
    }
}
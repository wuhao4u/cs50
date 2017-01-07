#include <cs50.h>
#include <stdio.h>
#include <math.h>

int coin_return(float changes);

int main(void) {
    float change_owed = 0.f;
    printf("O hai!");
    do {
        printf("How much change is owed?\n");
        change_owed = get_float();
    } while(change_owed < 0);
    
    printf("%d\n", coin_return(change_owed));
    return 0;
}

int coin_return(float changes) {
    int ret = 0;
    int left = (int)roundf(changes * 100);

    while (left > 0) {
        if(left >= 25) {
            left -= 25;
        } else if (left >= 10) {
            left -= 10;
        } else if (left >= 5) {
            left -= 5;
        } else if (left >= 1){
            left -= 1;
        }
        ret++;
    }
    return ret;
}


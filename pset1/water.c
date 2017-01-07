#include <cs50.h>
#include <stdio.h>

int main(void) {
    printf("Minutes: ");
    float min = get_float();
    printf("Bottles: %f\n", min * 12);
}
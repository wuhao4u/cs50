/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // validating the input. there could only be 2 or 3 arguments.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // converting the 2nd argument (n: the amount of pseuforandom number to generate),
    // from string to integer
    int n = atoi(argv[1]);

    // the 3rd argument(seed for random number generator) is optional
    if (argc == 3)
    {
        // if the user inputed the 3rd argument, seed the number
        srand48((long) atoi(argv[2]));
    }
    else
    {
        // using current time as the default seed
        srand48((long) time(NULL));
    }

    // generate n numbers with drand48.
    // drand48 generate a number between [0, 1). 
    // Thus, we need to multiply with LIMIT to convert from decimal number to a integer
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}

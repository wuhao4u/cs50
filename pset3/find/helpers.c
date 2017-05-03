/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    return false;
}

bool binary_search(int value, int values[], int n) {
    /*
    int start = 0;
    int end = n;
    
    while (start + 1 < end) {
        if (v)
    }
*/    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    if (n <= 1) {
        return values;
    }
    
    int half = n/2;
    int leftVals[] = malloc(sizeof(int) * half);
    int rightVals[] = malloc(sizeof(int) * half)

    int leftVals = sort(values[], n/2)
    for(int i = 0; i < n; ++i) {
        if (i < half) {
            leftVals[i] = values[i];
        } else {
            rightVals[i - half] = values[i];
        }
    }
    
    // sort left
    sort(leftVals, half);

    // sort right
    sort(rightVals, half);
    
    // merge
    return;
}

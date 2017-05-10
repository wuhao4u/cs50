/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

void swap(int values[], int i, int j) {
    int temp = values[i];
    values[i] = values[j];
    values[j] = temp;
}

bool linear_search(int value, int values[], int n) {
    for (int i = 0; i < n; ++i) {
        if (values[i] == value) {
            return true;
        }
    }

    return false;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    return linear_search(value, values, n);
//    return false;
}



void bubble_sort(int values[], int n) {
    int counter = -1;

    while (counter != 0) {
        counter = 0;
        for (int i = 0; i < n; ++i) {
            if(values[i] > values[i+1]) {
                // swap
                swap(values, i, i+1);
                ++counter;
            }
        }
    }
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    bubble_sort(values, n);
    return;
}

/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
//#include <cs50.h>

#include "helpers.h"
#include <stdlib.h>
#include <stdio.h>

void printIntArray(int values[], int n) {
    printf("------\n");
    for(int i = 0; i < n; ++i) {
        printf("[%d]: %d\n", i, values[i]);
    }
}

void swap(int values[], int i, int j) {
    int temp = values[i];
    values[i] = values[j];
    values[j] = temp;
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

int* hao_mergesort(int values[], int n) {
    if(n <= 1) {
        return values;
    }

    int firstHalf = n/2;
    int secondHalf = firstHalf;

    if(n % 2 != 0) {
        secondHalf += 1;
    }

    int* leftVals = (int*)malloc(sizeof(int) * firstHalf);
    int* rightVals = (int*)malloc(sizeof(int) * secondHalf);

    for(int i = 0; i < n; ++i) {
        if (i < firstHalf) {
            leftVals[i] = values[i];
        } else {
            rightVals[i - firstHalf] = values[i];
        }
    }

//    printIntArray(leftVals, firstHalf);
//    printIntArray(rightVals, secondHalf);

    // sort left
    hao_mergesort(leftVals, firstHalf);

    // sort right
    hao_mergesort(rightVals, secondHalf);

    // merge
    int lPtr = 0;
    int rPtr = 0;
    int i = 0;

    // TODO: finish this!
    while (lPtr < firstHalf || rPtr < secondHalf) {
        if(leftVals[lPtr] < rightVals[rPtr]) {
            values[i] = leftVals[lPtr];
            i++;
            lPtr++;
        } else {
            values[i] = rightVals[rPtr];
            i++;
            rPtr++;
        }
    }

    printIntArray(leftVals, firstHalf);
    printIntArray(rightVals, secondHalf);

    return values;
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
    if (n <= 1) {
        return;
    }

//    hao_mergesort(values, n);

    bubble_sort(values, n);
    printIntArray(values, n);
    return;
}

int main() {
    int test[] = {7,6,5,4,3,2,1,0};

    sort(test, 8);

    int quest = 4;
    if(search(quest, test, 8)) {
        printf("found number %d \n", quest);
    } else {
        printf("did not find number %d \n", quest);
    }

    return 0;
}
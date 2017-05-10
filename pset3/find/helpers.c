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

bool binary_search(int target, int A[], int n) {
    if (n == 0) {
        return false;
    }
    
    int start = 0;
    int end = n - 1;
    int mid;

        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (A[mid] == target) {
                end = mid;
            } else if (A[mid] < target) {
                start = mid;
            } else if (A[mid] > target) {
                end = mid;
            }
        }

        if (A[start] == target) {
            return true;
        }

        if (A[end] == target) {
            return true;
        }
        
    return false;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    // return linear_search(value, values, n);
    return binary_search(value, values, n);
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

void qsort_hao(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return;

    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort_hao(v, left, last-1);
    qsort_hao(v, last+1, right);
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    // bubble_sort(values, n);
    qsort_hao(values, 0, n);
    return;
}

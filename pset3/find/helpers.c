/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <limits.h>

#include "helpers.h"

void swap(int values[], int i, int j)
{
    if(i==j) return;
    
    int temp = values[i];
    values[i] = values[j];
    values[j] = temp;
}

bool linear_search(int value, int values[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        if (values[i] == value)
        {
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
    // TODO: implement binary search
    return linear_search(value, values, n);
}

// find the index that has the minimum value between [b, e) in 'values'
int find_min_value_index(int values[], const int b, const int e)
{
    int ret = -1;
    int curMinVal = INT_MAX;
    for (int i = b; i < e; ++i)
    {
        if(values[i] < curMinVal)
        {
            ret = i;
            curMinVal = values[i];
        }
    }
    return ret;
}

void selection_sort(int values[], int n)
{
    int i=0, j=0;
    while (i < n-1)
    {
        // find the minimum value in the unsorted part of the list
        j = i;
        j = find_min_value_index(values, i, n);
        swap(values, i, j);
        ++i;
    }
}

void merge_sort(int values[], int n)
{
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    selection_sort(values, n);
    return;
}

int main()
{
    // TODO: test sort
    int test[] = {2,5,4,6,7,9,8,1};
}
#include "header.h"

int return_max(int arr[], int n)
{
    int maxim = 0;
    int imax;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxim)
        {
            maxim = arr[i];
            imax = i;
        }
    }
    return imax;
}
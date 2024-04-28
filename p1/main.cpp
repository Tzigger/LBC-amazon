#include "header.h"
#include <iostream>
#include <fstream>
using namespace std;



int main()
{
    int k;
    int arr[MAXX_PRODUCTS];
    int suma = 0;
    
    int imaxim = 0;

    ifstream input("input.txt");
    ofstream output("output.txt");

    input >> k;
    int i = 0;
    while(input >> arr[i++]);
    int n = i-1;

    for(i = 0; i < k; i++)
    {
        imaxim = return_max(arr, n);
        suma += arr[imaxim];
        --arr[imaxim];
    }

    output << suma;
     

    return 0;
}
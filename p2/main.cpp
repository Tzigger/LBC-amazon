#include "header.h"
#include <iostream>

using namespace std;

int main()
{   
    int buget;
    ifstream input("input.txt");
    ofstream output("output.txt");
    input >> buget;

    Nod* rad = new Nod;
    rad = 0;
    int x;
    while(input>>x)
    {
        Insert(rad,x);
    }

    afisare_inordine(rad);
    cout<<endl;

    int k = 0;

    //cout << "Numarul maxim de planete indepartate care pot fi vizitate in bugetul de timp alocat este: " << maxim(rad, buget) << endl;









    return 0;
}
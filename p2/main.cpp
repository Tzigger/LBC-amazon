#include "header.h"
#include <iostream>

using namespace std;

int main()
{
    int buget;
    ifstream input("input.txt");
    ofstream output("output.txt");
    input >> buget;

    Nod *rad = new Nod;
    rad = 0;
    int x;
    while (input >> x)
    {
        Insert(rad, x);
    }

    afisare_inordine(rad);
    cout << endl;

    int k = 0;

    Coada q = INITQ();

    get_leaf_nodes(rad, q);

    cout << "Nr maxim de planete vizitate este: " << det_max(rad, q, buget) << endl;

    return 0;
}
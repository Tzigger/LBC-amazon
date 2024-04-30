#include "header.h"


using namespace std;

int main()
{   
    int buget;
    ifstream input("input.txt");
    ofstream output("output.txt");
    input >> buget;

    Nod* rad = creare_arbore(input);
    









    return 0;
}
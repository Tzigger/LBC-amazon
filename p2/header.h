#ifndef _HEADER_H_
#define _HEADER_H_
#include <fstream>
using namespace std;

struct Nod
{
    int planeta;
    Nod *st, *dr;
};

Nod* creare_nod(int x);
void Insert(Nod*& rad, int x);
Nod* creare_arbore(ifstream& input);


#endif
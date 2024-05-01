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
void afisare_inordine(Nod* rad);

struct Elem
{
    int planeta;
    Elem *succ;
};

struct Coada
{
    Elem *tail, *head;
};


Coada INITQ();
int isempty(Coada q);
void PUT(Coada &q, int x);
void GET(Coada &q);




#endif
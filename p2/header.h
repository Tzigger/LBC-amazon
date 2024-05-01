#ifndef _HEADER_H_
#define _HEADER_H_
#include <fstream>
using namespace std;

#define MAXX 10 // reprezinta nr maxim de frunze ce vor fi acceptate

struct Nod
{
    int planeta;
    Nod *st, *dr;
};

Nod *creare_nod(int x);
void Insert(Nod *&rad, int x);
void afisare_inordine(Nod *rad);

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
int FRONT(Coada& q);
void PUT(Coada &q, int x);
int GET(Coada &q);
void get_leaf_nodes(Nod *rad, Coada &q);
int get_level(Nod *rad, int x, int level);
int det_max(Nod *rad, Coada &q, int buget);

#endif
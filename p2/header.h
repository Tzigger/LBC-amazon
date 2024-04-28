#ifndef _HEADER_H_
#define _HEADER_H_
#include <fstream>

struct Nod
{
    int planeta;
    Nod *st, *dr;
};

static void eroare();
char readchar();
Nod *citesteArbore();

#endif
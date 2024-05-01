#include "header.h"
#include <iostream>


Nod* creare_nod(int x)
{
	Nod* p = new Nod;
	p->planeta = x;
	p->st = p->dr = 0;
	return p;
}

void Insert(Nod*& rad, int x)
{
	if(rad == 0)
	{
		rad = creare_nod(x);
		return; 
	}
	if( x < rad->planeta)
	{
		Insert(rad->st, x);
	}
	else
	{
		if(rad->planeta < x)
		{
			Insert(rad->dr, x);
		}
	}
}

void afisare_inordine(Nod *rad)
{
	if (rad)
	{
		afisare_inordine(rad->st);
		std::cout << rad->planeta << " ";
		afisare_inordine(rad->dr);
	}
}

Coada INITQ()
{
	Coada q;
	q.head= q.tail = 0;
	return q;
}

int isempty(Coada q)
{
	return (q.head == 0 && q.tail == 0);
}

void PUT(Coada &q, int x)
{
    Elem *p = new Elem;
    p->planeta = x;
    p->succ = 0;
    q.tail->succ = p;
    q.tail = p;
}

void GET(Coada &q)
{
    Elem *p = q.head;
    char aux = p->planeta;
    q.head = p->succ;
    delete p;
}


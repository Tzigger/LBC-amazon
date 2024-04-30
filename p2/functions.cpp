#include "header.h"

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
		if(rad->planeta == x)
		{
			Insert(rad->dr, x);
		}
	}
}

Nod* creare_arbore(ifstream& input)
{
	Nod *rad = new Nod;
	int x;
	while(input >> x)
	{
		Insert(rad,x);
	}
	return rad;	
}


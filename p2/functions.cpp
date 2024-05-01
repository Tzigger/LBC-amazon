#include "header.h"
#include <iostream>

Nod *creare_nod(int x)
{
	Nod *p = new Nod;
	p->planeta = x;
	p->st = p->dr = 0;
	return p;
}

void Insert(Nod *&rad, int x)
{
	if (rad == 0)
	{
		rad = creare_nod(x);
		return;
	}
	if (x < rad->planeta)
	{
		Insert(rad->st, x);
	}
	else
	{
		if (rad->planeta < x)
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
	q.head = q.tail = 0;
	return q;
}

void PUT(Coada &q, int x)
{
	Elem *p = new Elem;
	p->planeta = x;
	p->succ = 0;
	if (q.head == 0)
	{
		q.head = p;
	}
	else
	{
		q.tail->succ = p;
	}
	q.tail = p;
}

int GET(Coada &q)
{
	Elem *p = q.head;
	if(p == NULL)
		return 0; // cod eroare
	int aux = p->planeta;
	q.head = p->succ;
	delete p;

	return aux;
}

int FRONT(Coada& q)
{
	Elem *p = q.head;
	if(p == NULL)
		return -1; // cod eroare
	int aux = p->planeta;
	return aux;
}

void get_leaf_nodes(Nod *rad, Coada &q)
{
	if (rad == NULL)
		return;

	get_leaf_nodes(rad->st, q);

	if (rad->st == NULL && rad->dr == NULL)
		PUT(q, rad->planeta);

	get_leaf_nodes(rad->dr, q);
}

int get_level(Nod *rad, int x, int level)
{
	if (rad == NULL)
		return 0;

	if (rad->planeta == x)
		return level;

	int l = get_level(rad->st, x, level + 1);
	if (l != 0)
		return l;

	return get_level(rad->dr, x, level + 1);
}

int det_max(Nod *rad, Coada &q, int buget)
{
	int maxim = 0;
	int cost = 0;
	if (rad == NULL)
		return 0;

	while (FRONT(q) != -1)
	{
		int x = GET(q);
		cost += get_level(rad, x, 1);
		if (cost <= buget)
			++maxim;
		else
			return maxim;
	}

	return maxim;
}
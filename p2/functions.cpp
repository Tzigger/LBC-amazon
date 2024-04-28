#include "header.h"
using namespace std;


ifstream input("input.txt");
ifstream output("output.txt");
int buget;


char car;

static void eroare()
{
	exit(1);
}

char readchar()
{
	char c;
	do  input >> c;  while (c == ' ');
	return c;
}

int citeste_planeta()
{
	int c;
	if (!isalpha(car)) eroare();
	c = car;
	car = readchar();
	return c;
}

Nod* citesteArbore()
{
	Nod* rad;
	if (car == '-')
	{
		rad = 0;
		car = readchar();
	}
	else
	{
		rad = new Nod;
		rad->planeta = citeste_planeta();
		if (car != '(')
		{
			rad->st = 0;
			rad->dr = 0;
		}
		else
		{
			car = readchar();
			rad->st = citesteArbore();
			if (car != ',')
			{
				rad->dr = 0;
			}
			else
			{
				car = readchar();
				rad->dr = citesteArbore();
			}
			if (car != ')')  eroare();
			car = readchar();
		}
	}
	return rad;
}

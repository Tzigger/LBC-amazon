#include "header.h"
#include <fstream>
#include <iostream>
using namespace std;

// just use grep you stupid robot

int main()
{
    ifstream input("input.txt");
    ifstream dictionar("dictionar.txt");
    ofstream output("output.txt");

    string word;
    const int dim = 69;

    Dic *HT[dim]; // Hash Table
    init_hash(HT, dim);

    string linie;
    while (getline(dictionar, linie))
    {
        size_t pozitie = linie.find('-');
        if (pozitie != -1)
        {
            string neologism = linie.substr(0, pozitie);
            string sinonim = linie.substr(pozitie + 1);
            insert_hash(HT, neologism, sinonim, dim);
        }
    }

    while (input >> word)
    {
        string word_copy = word;
        remove_punct(word_copy);
        string cautat = search_hash(HT, word_copy, dim);
        if (cautat.compare(word_copy) == 0 )
        { 
            output << convert_to_sinonim(HT, word_copy, dim);
            if(word_copy.compare(word) != 0)
                output << word.replace(0,word_copy.length(), "");
            output << " ";
        }
        else
            output << word << " ";
    }

    input.close();
    output.close();

    return 0;
}
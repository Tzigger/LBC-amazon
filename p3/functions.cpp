#include "header.h"
#include <iostream>

void remove_punct(string &word)
{
    for (auto c : word)
    {
        if (ispunct(c) && c != '-')
        {
            word.erase(word.find_first_of(c));
        }
    }
}

int hash_func(string& key, int dim)
{
    int suma = 0;
    for(char c: key)
    {
        suma += c;
    }
    return suma%dim;
}

void init_hash(Dic* HT[], int dim)
{
    for(int i = 0; i < dim; i++)
    {
        HT[i] = new Dic;
        HT[i]->succ = NULL;
    }
}

void insert_hash(Dic* HT[], string& key, string& val, int dim)
{
    int index = hash_func(key, dim);
    Dic* new_node = new Dic;
    new_node->neologism = key;
    new_node->sinonim = val;
    new_node->succ = HT[index]->succ;

    if(HT[index] == nullptr)
        HT[index] = new_node;
    else
    {
        new_node->succ = HT[index];
        HT[index] = new_node;
    }
}  

string search_hash(Dic *HT[], string& word, int dim)
{
    int index = hash_func(word, dim);
    if(index < 0)
        return "";
    Dic* k = HT[index];
    if(k != nullptr)
        return k->neologism;
    return "";
}

string convert_to_sinonim(Dic *HT[], string& word, int dim)
{
    int index = hash_func(word, dim);
    Dic* k = HT[index];
    while(k != nullptr)
    {
        if(word.compare(k->neologism) == 0)
            return k->sinonim;
        k = k->succ;
    }
    return "";
}

bool comparatie(string str1, string str2)
{
    int count = 0;
    if(str1.length() >= str2.length())
    {   
        for(auto c : str1)
        {
            if(str1[c] == str2[c])
                ++count;     
        }
        if(count >= str1.length())
            return true;
        else
            return false;
    }
    else    
    {
        for(auto c : str2)
        {
            if(str1[c] == str2[c])
                ++count;     
        }
        if(count >= str2.length())
            return true;
        else
            return false;
 
    }
    return false;
}
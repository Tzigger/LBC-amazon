#ifndef _HEADER_H_
#define _HEADER_H_

#include <string>
using namespace std;

struct Dic{
    string neologism;
    string sinonim;
    Dic *succ;
};

void init_hash(Dic* HT[], int dim);

void remove_punct(string &word);
int hash_func(string& key, int dim);
void insert_hash(Dic* HT[], string& key, string& val, int dim);
string search_hash(Dic *HT[], string& word, int dim);
string convert_to_sinonim(Dic *HT[], string& word, int dim);
bool comparatie(string str1, string str2);
#endif
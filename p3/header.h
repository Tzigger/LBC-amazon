#ifndef _HEADER_H_
#define _HEADER_H_

#include <string>
using namespace std;

struct dictionar{
    string cuvant;
    string neologism;
};

void remove_punct(string &word);

#endif
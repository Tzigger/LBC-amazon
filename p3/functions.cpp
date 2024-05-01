#include "header.h"

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


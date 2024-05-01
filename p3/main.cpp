#include "header.h"
#include <fstream>
#include <iostream>
int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    string word;
    while(input >> word)
    {
        remove_punct(word);

        output << word << endl;
    }

    


    input.close();
    output.close();

    return 0;
}
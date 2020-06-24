#include "BoyerMoore.h"
#include <chrono> 
#include <iostream>
#include <fstream>
#define ARRAYSIZE 10000

#include <stdlib.h>
#include <stdio.h>
using namespace std;
using namespace std::chrono;

int main()
{
    char txt[ARRAYSIZE];
    char current_char;
    int num_characters = 0;
    int i = 0;

    ifstream genomeSequence("SARS_Covid.txt");

    if (genomeSequence.is_open())
    {
        while (!genomeSequence.eof())
        {
            if ((genomeSequence.get() != ' ') && (genomeSequence.get() != '\n'))
            {
                genomeSequence >> txt[i];
                i++;
                num_characters++;
            }
        }
    }


    char pat[] = "tga";

    /*******************
    START TIMER
    *******************/
    auto start = high_resolution_clock::now();

    /*******************
         ALGORITMO
    *******************/
    search(txt, pat);

    /*******************
        END TIMER
    *******************/
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

   cout << endl << "\nCOUNT = " << duration.count() << endl;

    return 0;
}
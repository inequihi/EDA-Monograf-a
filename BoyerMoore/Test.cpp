#include "BoyerMoore.h"
#include <chrono> 
#include <iostream>
#include <fstream>
#define ARRAYSIZE 100000

#include <stdlib.h>
#include <stdio.h>
using namespace std;
using namespace std::chrono;

int main()
{
    char txt[ARRAYSIZE];
    char txt_part2[ARRAYSIZE];
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

    i = 0;
    num_characters = 0;
    ifstream genomeSequence2("SARS_Covid2.txt");

    if (genomeSequence2.is_open())
    {
        while (!genomeSequence2.eof())
        {
            if ((genomeSequence2.get() != ' ') && (genomeSequence2.get() != '\n'))
            {
                genomeSequence2 >> txt_part2[i];
                i++;
                num_characters++;
            }
        }
    }

    ////////////////TRIAL1///////////////////
    char pat[] = "agtg";

    /*******************
    START TIMER
    *******************/
    auto start = high_resolution_clock::now();

    /*******************
         ALGORITMO
    *******************/
    search(txt, pat);
    search(txt_part2, pat);

    /******************
        END TIMER
    *******************/
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << endl << "\nCOUNT = " << duration.count() << endl;



    ////////////////TRIAL2///////////////////

    char pat1[] = "tgag";

    /*******************
     START TIMER
     *******************/
    auto start1 = high_resolution_clock::now();

    /*******************
         ALGORITMO
    *******************/
    search(txt, pat1);
    search(txt_part2, pat1);

    /*******************
        END TIMER
    *******************/
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    cout << endl << "\nCOUNT = " << duration1.count() << endl;



    ////////////////TRIAL3///////////////////
    char pat2[] = "atga";

    /*******************
     START TIMER
     *******************/
    auto start2 = high_resolution_clock::now();

    /*******************
         ALGORITMO
    *******************/
    search(txt, pat2);
    search(txt_part2, pat2);

    /*******************
        END TIMER
    *******************/
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout << endl << "\nCOUNT = " << duration2.count() << endl;


   ////////////////TRIAL4///////////////////
   char pat3[] = "gtta";

   /*******************
    START TIMER
    *******************/
   auto start3 = high_resolution_clock::now();

   /*******************
        ALGORITMO
   *******************/
   search(txt, pat3);
   search(txt_part2, pat3);

   /*******************
       END TIMER
   *******************/
   auto stop3 = high_resolution_clock::now();
   auto duration3 = duration_cast<microseconds>(stop3 - start3);

   cout << endl << "\nCOUNT = " << duration3.count() << endl;



   ////////////////TRIAL5///////////////////
   char pat4[] = "aaaa";

   /*******************
    START TIMER
    *******************/
   auto start4 = high_resolution_clock::now();

   /*******************
        ALGORITMO
   *******************/
   search(txt, pat4);
   search(txt_part2, pat4);

   /*******************
       END TIMER
   *******************/
   auto stop4 = high_resolution_clock::now();
   auto duration4 = duration_cast<microseconds>(stop4 - start4);

   cout << endl << "\nCOUNT = " << duration4.count() << endl;



   ////////////////TRIAL6///////////////////
   char pat5[] = "tttt";

   /*******************
    START TIMER
    *******************/
   auto start5 = high_resolution_clock::now();

   /*******************
        ALGORITMO
   *******************/
   search(txt, pat5);
   search(txt_part2, pat5);

   /*******************
       END TIMER
   *******************/
   auto stop5 = high_resolution_clock::now();
   auto duration5 = duration_cast<microseconds>(stop5 - start5);

   cout << endl << "\nCOUNT = " << duration5.count() << endl;



   ////////////////TRIAL6///////////////////
   char pat6[] = "gggg";

   /*******************
    START TIMER
    *******************/
   auto start6 = high_resolution_clock::now();

   /*******************
        ALGORITMO
   *******************/
   search(txt, pat6);
   search(txt_part2, pat6);

   /*******************
       END TIMER
   *******************/
   auto stop6 = high_resolution_clock::now();
   auto duration6 = duration_cast<microseconds>(stop6 - start6);

   cout << endl << "\nCOUNT = " << duration6.count() << endl;

   
   return 0;
}
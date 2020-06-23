
#include "RabinKarp.h"
#include <chrono> 
#include <iostream> 

using namespace std;
using namespace std::chrono;

int main()
{

    char txt[] = "ABAAABCD";
    char pat[] = "ABC";
    int q = 101;

    /*******************
    START TIMER
    *******************/
    auto start = high_resolution_clock::now();

    /*******************
         ALGORITMO
    *******************/
    search(pat, txt, q);

    /*******************
        END TIMER
    *******************/
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << endl << "\nCOUNT = " << duration.count() << endl;

    return 0;
}


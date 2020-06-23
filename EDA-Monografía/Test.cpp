#include "BoyerMoore.h"
#include <chrono> 
#include <iostream> 

using namespace std;
using namespace std::chrono;

int main()
{

    char txt[] = "ABAAABCD";
    char pat[] = "ABC";

    auto start = high_resolution_clock::now();
    search(txt, pat);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

   cout << endl << "COUNT = " << duration.count() << endl;

    return 0;
}
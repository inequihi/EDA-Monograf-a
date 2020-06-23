
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

    auto start = high_resolution_clock::now();
    search(pat, txt, q);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << endl << "COUNT = " << duration.count() << endl;

    return 0;
}


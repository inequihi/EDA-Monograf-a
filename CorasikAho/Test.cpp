#include "AhoCorasik.h"
#include <chrono> 
#include <iostream> 
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#define TEST1
using namespace std;
using namespace std::chrono;

int buildMatchingMachine(const vector<string>& words, char lowestChar = 'a',
    char highestChar = 'z')
{
    memset(out, 0, sizeof out);
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    int states = 1; // Initially, we just have the 0 state
    for (int i = 0; i < words.size(); ++i)
    {
        const string& keyword = words[i];
        int currentState = 0;
        for (int j = 0; j < keyword.size(); ++j)
        {
            int c = keyword[j] - lowestChar;
            if (g[currentState][c] == -1)
            { // Allocate a new node
                g[currentState][c] = states++;
            }
            currentState = g[currentState][c];
        }
        out[currentState] |= (1 << i); // There's a match of keywords[i] at node currentState.
    }
    // State 0 should have an outgoing edge for all characters.
    for (int c = 0; c < MAXC; ++c)
    {
        if (g[0][c] == -1)
        {
            g[0][c] = 0;
        }
    }

    // Now, let's build the failure function
    queue<int> q;
    for (int c = 0; c <= highestChar - lowestChar; ++c)
    { // Iterate over every possible input
    // All nodes s of depth 1 have f[s] = 0
        if (g[0][c] != -1 and g[0][c] != 0)
        {
            f[g[0][c]] = 0;
            q.push(g[0][c]);
        }
    }
    while (q.size())
    {
        int state = q.front();
        q.pop();
        for (int c = 0; c <= highestChar - lowestChar; ++c)
        {
            if (g[state][c] != -1)
            {
                int failure = f[state];
                while (g[failure][c] == -1)
                {
                    failure = f[failure];
                }
                failure = g[failure][c];
                f[g[state][c]] = failure;
                out[g[state][c]] |= out[failure]; // Merge out values
                q.push(g[state][c]);
            }
        }
    }

    return states;
}
int findNextState(int currentState, char nextInput, char lowestChar = 'a')
{
    int answer = currentState;
    int c = nextInput - lowestChar;
    while (g[answer][c] == -1)
        answer = f[answer];
    return g[answer][c];
}


int main()
{
    /*******************
      GUARDAMOS GENOMA
    *******************/
    string text;
   stringstream buffer;
    buffer << ifstream("SARS_Covid.txt").rdbuf();
    text = buffer.str();

    unsigned int Ocurrencias = 0;

    vector<string> keywords;

    keywords.push_back("gggg");


    buildMatchingMachine(keywords, 'a', 'z');
    int currentState = 0;

    /*******************
        START TIMER
    *******************/
    auto start = high_resolution_clock::now();

    /*******************
         ALGORITMO
    *******************/
    for (int i = 0; i < text.size(); ++i)
    {
        currentState = findNextState(currentState, text[i], 'a');
        if (out[currentState] == 0)
            continue; // Nothing new, let's move on to the next character.
        for (int j = 0; j < keywords.size(); ++j)
        {
            if (out[currentState] & (1 << j))
            { // Matched keywords[j]
                cout << "Keyword " << keywords[j] << " appears from " << i
                    - keywords[j].size() + 1 << " to " << i << endl;

                Ocurrencias += 1;
            }
        }
    }

    /*******************
        END TIMER
    *******************/
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << endl << "COUNT = " << duration.count() << endl << "OCURRENCIAS =" << Ocurrencias ;

    return 0;
}
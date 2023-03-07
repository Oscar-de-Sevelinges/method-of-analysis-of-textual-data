#include <iostream>
#define NB_OF_CHAR 256

using namespace std;

int getNextState(string pat, int M, int state, int x)
{
    if(state < M && x == pat[state])
    {
        return state+1;
    }
    int ns, i;
    for(ns = state; ns > 0; ns--)
    {
        if(pat[ns-1] == x)
        {
            for(i = 0; i < ns-1; i++)
            {
                if(pat[i] != pat[state-ns+i+1])
                {
                    break;
                }
            }
            if(i == ns-1)
            {
                return ns;
            }
        }
    }
    return 0;
}

void initDFA(const string& pat, int M, int FA[][NB_OF_CHAR])
{
    int state, x;
    for(state = 0; state < M+1; state++)
    {
        for(x = 0; x < NB_OF_CHAR; x++)
        {
            FA[state][x] = getNextState(pat, M, state, x);
        }
    }
}

void searchPat(const string& pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
    int FA[M+1][NB_OF_CHAR];
    int i, state = 0;
    initDFA(pat, M, FA);
    for(i = 0; i < N; i++)
    {
        state = FA[state][txt[i]];
        if(state == M)
        {
            cout << "pattern found at index " << i-M+1 << endl;
        }
    }
}

int main() {
    string txt = "GAATCATTCGGATATTCGAC";
    string pat = "ATTC";
    searchPat(pat, txt);
    return 0;
}

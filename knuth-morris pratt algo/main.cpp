#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void computeLPS(vector<int> lps, int M, const char* pat)
{
    int i = 1, len = 0;
    lps[0] = 0;
    while(i < M)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if(pat[i] != pat[len])
        {
            if(len != 0)
            {
                len--;
                //len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char* txt, char* pat)
{
    int N = strlen(txt);
    int M = strlen(pat);

    vector<int> lps(M);
    computeLPS(lps, M, pat);

    int i = 0, j = 0;

    do
    {
        if(pat[j] == txt[i])
        {
            i++;
            j++;
        }

        if(j == M)
        {
            cout << "pattern found at index " << i-j << endl;
            j = lps[j-1];
        }

        else if(i < N && pat[j] != txt[i])
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }while(i < N);
}

int main()
{
    char txt[] = "this is a test";
    char pat[] = "test";
    cout << "pattern : " << endl << pat << endl << endl;
    cout << "text : " << endl << txt << endl;
    for(unsigned int i = 0; i < strlen(txt); i++)
    {
        cout << i;
    }
    cout << endl << endl;
    KMP(txt, pat);
    return 0;
}

#include "kmp.h"

void computeLPS(std::vector<int> lps, int M, std::string pat)
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
                //len--;
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(std::string pat, std::string txt)
{
    int N = txt.size();
    int M = pat.size();

    std::vector<int> lps(M);
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
            std::cout << "pattern found at index " << i-j << std::endl;
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

#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

void shiftTable(string p, int shift[])
{
    int i, m;
    m = p.size();
    for(i = 0; i < 256; i++)
    {
        shift[i] = m;
    }
    for(i = 0; i < m-1; i++)
    {
        shift[p[i]] = m-i-1;
    }
}

void horspool(string t, string p)
{
    int shift[256];
    shiftTable(p, shift);
    int m, n, k = 0;
    m = p.size();
    n = t.size();
    while(k <= n-m)
    {
        int j = m-1;
        while(j >= 0 && p[j] == t[k+j])
        {
            j--;
        }
        if(j < 0)
        {
            cout << "pattern found at index " << k << " " << endl;
            k += (k + m < n)? m-shift[t[k + m]] : 1;
        }
        else
        {
            k += max(1, j - shift[t[k + j]]);
        }
    }
}

int main()
{
    string txt;
    string pat = "TAGGCAC";
    std::ifstream ifs("dna.txt");
    if(!ifs)
    {
        std::cout << "error" << std::endl;
    }
    ifs >> txt;
    auto start = high_resolution_clock::now();
    horspool(txt, pat);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "duration : " << duration.count() << "us" << std::endl;
    return 0;
}

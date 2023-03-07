#include "horspool.h"

using namespace std;

std::vector<int> shiftTable(std::string p)
{
    int i, m;
    m = p.size();
    std::vector<int> shift;
    for(i = 0; i < 256; i++)
    {
        shift.push_back(m);
    }
    for(i = 0; i < m-1; i++)
    {
        shift[(int)p[i]] = m-i-1;
    }
    return shift;
}

void horspool(std::string p, std::string t)
{
    std::vector<int> shift = shiftTable(p);
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
            std::cout << "pattern found at index " << k << " " << std::endl;
            k += (k + m < n)? m-shift[(int)t[k + m]] : 1;
        }
        else
        {
            k += max(1, j - shift[(int)t[k + j]]);
        }
    }
}

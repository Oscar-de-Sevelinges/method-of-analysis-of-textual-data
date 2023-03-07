#include <iostream>

using namespace std;

void naivePatternDetection(string txt, string pat)
{
    int nbError = 0;
    // max number of pat detection in text
    for(unsigned int i = 0; i <= txt.size() - pat.size(); i++)
    {
        unsigned int j = 0;
        // for each letter of pat, check if it corresponds in text
        for(j = 0; j < pat.size(); j++)
        {
            // if letters don't match, we go out of the loop
            if(txt[i + j] != pat[j])
            {
                nbError++;
                if(nbError > 2)
                {
                    nbError = 0;
                    break;
                }
            }
        }
        // if every letters match with the text, we found a pattern in the text
        if(j == pat.size())
        {
            cout << "pattern found at index " << i << " with " << nbError << " error" << endl;
        }
    }
}

int main()
{
    string txt = "this is a test";
    string pat = "test";
    naivePatternDetection(txt, pat);
    return 0;
}

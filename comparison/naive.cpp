#include "naive.h"

void naivePatternDetection(std::string pat, std::string txt)
{
    // max number of pat detection in text
    for(unsigned int i = 0; i <= txt.size() - pat.size(); i++) // i represents the number of shift we made
    {
        unsigned int j = 0;
        // for each letter of pat, check if it corresponds in text
        for(j = 0; j < pat.size(); j++)
        {
            // if letter doesn't match, we go out of the loop to shift the pattern on the text
            if(txt[i + j] != pat[j])
            {
                break;
            }
        }
        // if every letters match with the text, we found a pattern in the text
        if(j == pat.size())
        {
            std::cout << "pattern found at index " << i << std::endl;
        }
    }
}

#ifndef KMP_H_INCLUDED
#define KMP_H_INCLUDED

#include <iostream>
#include <vector>
#include <cstring>

void computeLPS(std::vector<int> lps, int M, const char* pat);
void KMP(std::string pat, std::string txt);

#endif // KMP_H_INCLUDED

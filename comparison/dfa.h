#ifndef DFA_H_INCLUDED
#define DFA_H_INCLUDED

#include <iostream>
#define NB_OF_CHAR 256

int getNextState(std::string pat, int M, int state, int x);
void initFA(const std::string& pat, int M, int FA[][NB_OF_CHAR]);
void searchPat(const std::string& pat, std::string txt);

#endif // DFA_H_INCLUDED

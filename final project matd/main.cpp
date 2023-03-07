#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define MAXERROR 2

using namespace std;

int computeState(string txt, string pat, int state = 1, int txtIndex = 0, int patIndex = 0)
{
	// case of invalid end
	if (state > (MAXERROR + 1) * (pat.size() + 1)) return -1;

	// case of valid end
	if (state % (pat.size() + 1) == 0) return state;

	// if we have a match we call the same function and increment index of txt and pat, and also the state
	if (txt[txtIndex] == pat[patIndex]) return computeState(txt, pat, state + 1, txtIndex + 1, patIndex + 1);

	// if we have a missmatch we call the same function and increment indexes, and we go diagonally in the automaton
	int res1 = computeState(txt, pat, state + pat.size() + 2, txtIndex + 1, patIndex + 1);

	// if there is a missing letter in the text, we go diagonally in the automaton and we increment the index of the pattern
	int res2 = computeState(txt, pat, state + pat.size() + 2, txtIndex, patIndex + 1);
	if (res2 != -1)
	{
		if (res1 != -1)
		{
			if (res2 < res1)
			{
				res1 = res2;
			}
		}
		else res1 = res2;
	}

	// if there is an inserted letter in the text, we go down in the automaton and we increment the index of the text
	res2 = computeState(txt, pat, state + pat.size() + 1, txtIndex + 1, patIndex);
	if (res2 != -1)
	{
		if (res1 != -1)
		{
			if (res2 < res1)
			{
				res1 = res2;
			}
		}
		else res1 = res2;
	}

	return res1;
}

void approximatePatternMatching(pair<string, int> txt, string pat)
{
	// we compute the state of the word to see if we arrive in the final state of the automaton
	int state = computeState(txt.first, pat);
	if (state % (pat.size() + 1) == 0 && state / (pat.size() + 1) - 1 <= MAXERROR)
	{
		cout << "pattern found at index " << txt.second << endl;
		cout << "number of error : " << state / (pat.size() + 1) - 1 << endl << endl;
	}
	else
	{
		cout << pat << " doesn't match with the word " << txt.first << " at index " << txt.second << endl << endl;
	}
}

void preprocess(string txt, string pat)
{
	system("cls");
	cout << "maximum number of errors allowed : " << MAXERROR << endl << endl;

	// we put each word of the text in a vector of pair (the int represent the index of the forst letter of the word in the text)
	istringstream iss(txt);
	vector<pair<string, int>> words;
	int indexWord = 0;
	do
	{
		string word;
		iss >> word;
		if (indexWord < txt.size())
		{
			words.push_back(make_pair(word, indexWord));
		}
		indexWord += word.size() + 1;
	} while (iss);

	// we call the alg for each word in the text
	for (const auto& elem : words)
	{
		if (elem.first.size() > 1)
		{
			approximatePatternMatching(elem, pat);
		}
	}
}

int main()
{
	cout << "IMPLEMENTATION OF THE APPROXIMATE PATTERN MATCHING ALGORITHM IN CPP" << endl << endl;

	// dafault value for the text and the pattern
	string txt = "hello this is a text";
	string pat = "test";

	int choice;
	do
	{
		// 2 options : use deafult text and pattern or enter a new text and pattern
		cout << "choose an option :" << endl;
		cout << "1 : try the algorithm with txt = \"" << txt << "\" and pat = \"" << pat << "\"";
		cout << endl << "2 : enter your own text and own pattern" << endl;
		cin >> choice;
	} while ((choice != 1) && (choice != 2));

	switch (choice)
	{
	case 1:
		preprocess(txt, pat);
		break;
	case 2:
		cin.ignore(1000, '\n');
		cout << "enter your text : ";
		getline(cin, txt);
		cin.ignore(1000, '\n');
		cout << endl << "enter your pattern : ";
		cin >> pat;
		preprocess(txt, pat);
		break;
	default:
		break;
	}
	cout << txt << endl << pat;
	return 0;
}

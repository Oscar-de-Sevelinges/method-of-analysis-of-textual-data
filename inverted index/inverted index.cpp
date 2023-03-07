//////// ATTENTION : LES NUMS DE DOCS DOIVENT ETRE DANS L ORDRE CROISSANT POUR PAS AVOIR DE VALEUR NEGATIVE 
//////// DANS LA PARTIE COMPRESSION (CREER UN set<pair<string, vector<int>>>)

#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>

using namespace std;

void postList(std::set<std::pair<std::string, int>>& termDocId)
{
	std::set<std::pair<std::string, int>>::iterator it;
	std::cout << "Posting list : " << std::endl << std::endl;
	for (it = termDocId.begin(); it != termDocId.end(); it++)
	{
		std::set<std::pair<std::string, int>>::iterator itNext = it++;
		std::cout << (*it).first << " " << (*it).second;
		if ((*it).first == (*itNext).first)
		{
			std::cout << " " << (*itNext).second;
			it++;
		}
		std::cout << std::endl;
	}
	/*for (int i = 0; i < termDocId.size(); i++)
	{
		std::cout << termDocId[i].first << " " << termDocId[i].second;
		if ((termDocId[i].first == termDocId[i + 1].first) || (i != 0 && termDocId[i] == termDocId[i-1]))
		{
			std::cout << termDocId[i + 1].second;
			i++;
		}
		std::cout << std::endl;
	}*/
}

void putDocInSet(std::set<std::pair<std::string, int>>& termDocId, std::string docName)
{
	std::ifstream ifs(docName + ".txt");
	int docNum;
	ifs >> docNum;
	std::string word;
	while (!ifs.eof())
	{
		ifs >> word;
		termDocId.insert(std::make_pair(word, docNum));
	}

	ifs.close();
}

void processSet(std::set<std::pair<std::string, int>> termDocId)
{
	//std::sort(termDocId.begin(), termDocId.end());
	/*std::set<std::pair<std::string, int>>::iterator it;
	for (it = termDocId.begin(); it != termDocId.end(); it++)
	{
		if (*it == *std::next(it, 1))
		{
			termDocId.erase(it);
			it--;
		}
	}*/
	/*for (int i = 0; i < termDocId.size(); i++)
	{
		if (termDocId[i] == termDocId[i + 1])
		{
			termDocId.erase(termDocId.begin() + i);
			i--;
		}
	}*/
	postList(termDocId);
}

int main()
{
	std::string dataBasePath = "dataBase.txt";
	std::ifstream ifs(dataBasePath);
	std::string docName;
	std::set<std::pair<std::string, int>> termDocId;
	while (!ifs.eof())
	{
		ifs >> docName;
		putDocInSet(termDocId, docName);
	}
	ifs.close();
	postList(termDocId);
	return 0;
}

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	vector<double> doc1;
	for (int i = 0; i < 100; i++)
	{
		doc1.push_back(rand() % 10 + 1);
	}
	for (const auto& elem : doc1)
	{
		cout << elem << endl;
	}
	return 0;
}

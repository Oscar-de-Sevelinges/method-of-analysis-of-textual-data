#include <iostream>
#include <chrono>
#include <fstream>
#include "naive.h"
#include "kmp.h"
#include "dfa.h"
#include "horspool.h"

using namespace std;
using namespace std::chrono;

int main()
{
    //std::string txt = "AAGCTGGCTAGGCATTACGCTCATAGGCAACCT";
    std::string txt;
    std::ifstream ifs("dna.txt");
    ifs >> txt;
    std::string pat = "TAGGCAC";
    int choice;
    do
    {
        system("cls");
        std::cout << "0 : exit" << std::endl;
        std::cout << "1 : naive" << std::endl;
        std::cout << "2 : dfa" << std::endl;
        std::cout << "3 : kmp" << std::endl;
        std::cout << "4 : horspool" << std::endl;
        std::cout << "5 : all" << std::endl;
        std::cin >> choice;
    }while(choice < 0 || choice > 5);

    switch (choice)
    {
        case 0 :
            break;
        case 1 :
            {
                auto start = high_resolution_clock::now();
                naivePatternDetection(pat, txt);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                std::cout << "duration : " << duration.count() << "us" << std::endl;
                break;
            }
        case 2 :
            {
                auto start = high_resolution_clock::now();
                searchPat(pat, txt);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                std::cout << "duration : " << duration.count() << "us" << std::endl;
                break;
            }
        case 3 :
            {
                auto start = high_resolution_clock::now();
                KMP(pat, txt);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                std::cout << "duration : " << duration.count() << "us" << std::endl;
                break;
            }
        case 4 :
            {
                auto start = high_resolution_clock::now();
                horspool(pat, txt);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                std::cout << "duration : " << duration.count() << "us" << std::endl;
                break;
            }
        case 5 :
            {
                std::cout << "naive : " << std::endl;
                auto start1 = high_resolution_clock::now();
                naivePatternDetection(pat, txt);
                auto stop1 = high_resolution_clock::now();
                auto duration1 = duration_cast<microseconds>(stop1 - start1);
                std::cout << "duration : " << duration1.count() << "us" << std::endl;
                std::cout << std::endl << std::endl;

                std::cout << "dfa : " << std::endl;
                auto start2 = high_resolution_clock::now();
                searchPat(pat, txt);
                auto stop2 = high_resolution_clock::now();
                auto duration2 = duration_cast<microseconds>(stop2 - start2);
                std::cout << "duration : " << duration2.count() << "us" << std::endl;
                std::cout << std::endl << std::endl;

                std::cout << "kmp : " << std::endl;
                auto start3 = high_resolution_clock::now();
                KMP(pat, txt);
                auto stop3 = high_resolution_clock::now();
                auto duration3 = duration_cast<microseconds>(stop3 - start3);
                std::cout << "duration : " << duration3.count() << "us" << std::endl;
                std::cout << std::endl << std::endl;

                std::cout << "horspool : " << std::endl;
                auto start4 = high_resolution_clock::now();
                horspool(pat, txt);
                auto stop4 = high_resolution_clock::now();
                auto duration4 = duration_cast<microseconds>(stop4 - start4);
                std::cout << "duration : " << duration4.count() << "us" << std::endl;
                std::cout << std::endl << std::endl;
            }
        default : break;
    }
    return 0;
}

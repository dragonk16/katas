//
// Created by David on 19-Aug-19.
//

#ifndef CPP_KATAS_HPP
#define CPP_KATAS_HPP
#include <iostream>
#include <intrin.h>
#include <list>
#include <cmath>
#include <vector>



using namespace std;

class DirReduction
{
public:
        static vector<char>* StringToChar(vector<string> &str);
        static vector<string>* CharToString(vector<char> &str);
        static vector<string> dirReduc(vector<string> &arr);
        int test();
};




#endif //CPP_KATAS_HPP
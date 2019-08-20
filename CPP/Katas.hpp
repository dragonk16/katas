//
// Created by David on 19-Aug-19.
//

#ifndef CPP_KATAS_HPP
#define CPP_KATAS_HPP
#include <iostream>
#include <intrin.h>
#include <cmath>
#include <vector>



using namespace std;

class DirReduction
{
public:
        static int nextValid(vector<bool> valid,int index);
        static int previousValid(vector<bool> valid,int index);
        static vector<string> dirReduc(vector<string> &arr);
        int test();///sample tests
};


#endif //CPP_KATAS_HPP
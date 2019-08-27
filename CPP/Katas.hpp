//
// Created by David on 19-Aug-19.
//

#ifndef CPP_KATAS_HPP
#define CPP_KATAS_HPP
#include <iostream>
#include <intrin.h>
#include <cmath>
#include <vector>
#include "element.hpp"




using namespace std;

/**
 * https://www.codewars.com/kata/550f22f4d758534c1100025a
 */
class DirReduction
{
    static int nextValid(vector<bool> valid,int index);
    static int previousValid(vector<bool> valid,int index);
public:
        static vector<string> dirReduc(vector<string> &arr);
        int test();///sample tests
};

/**
 * https://www.codewars.com/kata/5277c8a221e209d3f6000b56
 */
class ValidBraces {
public:
    static bool valid_braces(std::string braces);
    int test();///sample tests
};
/**
 * part1 : https://www.codewars.com/kata/path-finder-number-1-can-you-reach-the-exit/train/cpp
 * part2 : https://www.codewars.com/kata/path-finder-number-2-shortest-path/train/cpp
 */
 class PathFinderPart{
     bool path3(string& maze,int* matrix, int row,int col, int n,int distance,int currentPath,element current);
     bool path(string& maze,int* matrix, int row,int col, int n,int distance);
         public:
    bool test1();
     bool test2();
     bool test3();
     bool path_finder1(string maze);///part1
     int path_finder2(string maze); ///part2
     int path_finder3(string maze);
 };
/***
 *
 */


#endif //CPP_KATAS_HPP
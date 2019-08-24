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
<<<<<<< Updated upstream


=======
/**
 * https://www.codewars.com/kata/5277c8a221e209d3f6000b56
 */
class ValidBraces {
public:
    static bool valid_braces(std::string braces);
    int test();///sample tests
};
/**
 * https://www.codewars.com/kata/path-finder-number-1-can-you-reach-the-exit/train/cpp
 */
 class PathFinderPart1{
 public:

   //  bool path(string maze,int *location,int n);
     bool path_finder(string maze);
 };
>>>>>>> Stashed changes
#endif //CPP_KATAS_HPP
//
// Created by David on 21-Aug-19.
//

#include "katas.hpp"

//(){}[]
bool ValidBraces::valid_braces(std::string braces) {
    vector<char> stack;
    char brace;
    for (auto i:braces) {
        if (i == '(' || i == '{' || i == '[') {
            stack.push_back(i);
            continue;
        }
        if (stack.empty())  ///stack is empty and so we cannot pop a brace
            return false;
        brace = stack.back();
        if (    (brace == '(' && i == ')') ||
                (brace == '{' && i == '}') ||
                (brace == '[' && i == ']'))
            stack.pop_back();
        else return false;
    }
    if (stack.empty()==false)
        return false;
    return true;
}
int ValidBraces::test()///sample tests
{
    bool run=valid_braces("()");
    bool expected=true;
    if (expected!= run)
        cout<<"failed"<<endl;


}
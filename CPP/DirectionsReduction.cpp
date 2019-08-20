//
// Created by David on 19-Aug-19.
//
#include <assert.h>
#include "Katas.hpp"
#include <List>



enum directions { North = -1, South, East, West};

int DirReduction::test() {
    std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
    std::vector<std::string> sol1 = {"WEST"};
    for (int i = 0; ans1.size() > i ; ++i) {
        cout<<ans1[i]<<" ,";
    }
    cout<<endl;
    std::vector<std::string> d2 = {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH"};
    std::vector<std::string> ans2 = DirReduction::dirReduc(d2);
    std::vector<std::string> sol2 = {"NORTH"};
    for (int i = 0; ans2.size() > i ; ++i) {
        cout<<ans2[i]<<" ,";
    }
    cout<<endl;
}

vector<char>* DirReduction::StringToChar(vector<string> &str) {
    vector<char> *Vec = new vector<char>;
    for (int i = 0; i < str.size(); ++i) {

        if (str[i][0] == 'N') {
            Vec->push_back('N');
        }
        if (str[i][0] == 'S') {
            Vec->push_back('S');
        }
        if (str[i][0] == 'E') {
            Vec->push_back('E');
        }
        if (str[i][0] == 'W') {
            Vec->push_back('W');
        }
    }
    return Vec;
}
vector<string>* DirReduction::CharToString(vector<char> &str) {
    vector<string> *Vec = new vector<string>;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'N') {
            Vec->push_back("NORTH");
        }
        if (str[i] == 'S') {
            Vec->push_back("SOUTH");
        }
        if (str[i] == 'E') {
            Vec->push_back("EAST");
        }
        if (str[i] == 'W') {
            Vec->push_back("WEST");
        }
    }
    return Vec;
}
vector<string> DirReduction::dirReduc(vector<string> &arr){
    vector<char> *current = StringToChar(arr);
    vector<char> *next = new vector<char>;
    
}
//vector<string> DirReduction::dirReduc(vector<string> &arr) {
//
//    vector<char> *current = StringToChar(arr);
//    vector<char> *next = new vector<char>;
//    if (arr.size()==0){
//        return arr;
//    }
//    do {
//        if (next->size() != 0) {
////            delete current;
//            current = next;
//            next = new vector<char>;
//        }
//        for (int i = 0; i < current->size(); ++i) {
//            if (i == current->size()-1) {
//                next->push_back((*current)[i]);
//                continue;
//            }
//            if ((*current)[i] == 'N' && (*current)[i + 1] == 'S') {
//                i++;
//                continue;
//            }
//            if ((*current)[i] == 'S' && (*current)[i + 1] == 'N') {
//                i++;
//                continue;
//            }
//            if ((*current)[i] == 'E' && (*current)[i + 1] == 'W') {
//                i++;
//                continue;
//            }
//            if ((*current)[i] == 'W' && (*current)[i + 1] == 'E') {
//                i++;
//                continue;
//            }
//            next->push_back((*current)[i]);
//            if (i == current->size() - 1) {
//                next->push_back((*current)[i + 1]);
//            }
//        }
//    } while (next->size() != current->size());
//
//    vector<string>* ret=CharToString(*next);
////    delete current;
////    delete next;
//    return *ret;
//}

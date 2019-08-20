//
// Created by David on 19-Aug-19.
//
#include <assert.h>
#include "Katas.hpp"
#include <List>





int DirReduction::test() {
    std::vector<std::string> d1 = {"EAST", "EAST", "WEST","EAST", "WEST", "WEST", "NORTH"};
    std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
    std::vector<std::string> sol1 = {"WEST"};
    cout << "sol - ans1" << endl;
    cout << sol1.size() << "   " << ans1.size() << endl;
    for (int i = 0; ans1.size() > i; ++i) {
        cout << (sol1[i] == ans1[i]) << endl;
    }
    cout << endl;
//    std::vector<std::string> d2 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "NORTH"};
//    std::vector<std::string> ans2 = DirReduction::dirReduc(d2);
//    std::vector<std::string> sol2 = {"NORTH"};
//    cout << "sol - ans2" << endl;
//    cout << sol2.size() << "   " << ans2.size() << endl;
//    for (int i = 0; ans2.size() > i; ++i) {
//        cout << (sol2[i] == ans2[i]) << endl;
//    }
//    cout << endl;
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

int nextValid(vector<bool> valid,int index) {
    index++;
    while (index < valid.size() && valid[index] != 1) {
        index++;
    }
    if (index >= valid.size()) {
        return -1;
    }
    return index;
}

int previousValid(vector<bool> valid,int index) {
    index--;
    while (index >= 0 && valid[index] != 1) {
        index--;
    }
    if (index < 0) {
        return -1;
    }
    return index;
}

vector<string> DirReduction::dirReduc(vector<string> &arr) {
    vector<char> *current = StringToChar(arr);//TODO delete this
    vector<bool> valid;
    valid.assign(arr.size(), 1);
    int right = 1, left = 0;
    while (right != -1) {
        if (left == -1) {
            left = right;
            right = nextValid(valid, right);
            if (right == -1) {
                break;
            }
        }
        if ((*current)[left] == 'N' && (*current)[right] == 'S') {
            valid[right] = valid[left] = 0;
            left = previousValid(valid, left);
            right = nextValid(valid, right);
            continue;
        }
        if ((*current)[left] == 'S' && (*current)[right] == 'N') {
            valid[right] = valid[left] = 0;
            left = previousValid(valid, left);
            right = nextValid(valid, right);
            continue;
        }
        if ((*current)[left] == 'E' && (*current)[right] == 'W') {
            valid[right] = valid[left] = 0;
            left = previousValid(valid, left);
            right = nextValid(valid, right);
            continue;
        }
        if ((*current)[left] == 'W' && (*current)[right] == 'E') {
            valid[right] = valid[left] = 0;
            left = previousValid(valid, left);
            right = nextValid(valid, right);
            continue;
        }
        left=right;
        right=nextValid(valid, right);
    }
    vector<string> *output = new vector<string>;
    for (int i = 0; i < arr.size(); ++i) {
        if (valid[i] == 1) {
            output->push_back(arr[i]);
        }
    }
    return *output;
}


//    vector<char> *next = new vector<char>;

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

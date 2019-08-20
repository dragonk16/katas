//
// Created by David on 19-Aug-19.
//
#include "Katas.hpp"

//sample tests
int DirReduction::test() {
    std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
    std::vector<std::string> sol1 = {"WEST"};
    cout << "sol - ans1" << endl;
    cout << sol1.size() << "   " << ans1.size() << endl;
    for (int i = 0; ans1.size() > i; ++i) {
        cout << (sol1[i] == ans1[i]) << endl;
    }
    cout << endl;
    std::vector<std::string> d2 = {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH"};
    std::vector<std::string> ans2 = DirReduction::dirReduc(d2);
    std::vector<std::string> sol2 = {"NORTH"};
    cout << "sol - ans2" << endl;
    cout << sol2.size() << "   " << ans2.size() << endl;
    for (int i = 0; ans2.size() > i; ++i) {
        cout << (sol2[i] == ans2[i]) << endl;
    }
    cout << endl;
}

//gets the next value for the Right index
int DirReduction::nextValid(vector<bool> valid,int index) {
    index++;
    while (index < valid.size() && valid[index] != 1) {
        index++;
    }
    if (index >= valid.size()) {
        return -1;
    }
    return index;
}

//gets the next value for the Left index
int DirReduction::previousValid(vector<bool> valid,int index) {
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
        if (arr[left] == "NORTH" && arr[right] == "SOUTH") {
            valid[right] = valid[left] = 0;
            left = previousValid(valid, left);
            right = nextValid(valid, right);
            continue;
        }
        if (arr[left] == "SOUTH" && arr[right] == "NORTH") {
            valid[right] = valid[left] = 0;
            left = previousValid(valid, left);
            right = nextValid(valid, right);
            continue;
        }
        if (arr[left] == "EAST" && arr[right] == "WEST") {
            valid[right] = valid[left] = 0;
            left = previousValid(valid, left);
            right = nextValid(valid, right);
            continue;
        }
        if (arr[left] == "WEST" && arr[right] == "EAST") {
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

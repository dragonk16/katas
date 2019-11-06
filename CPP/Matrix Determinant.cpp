//
// Created by David on 09-Oct-19.
//

#include <iostream>
#include <vector>
#include "katas.hpp"

using namespace std;


/// \param m the matrix to be trimmed, the row used as the coefficient will be skipped
/// \param index the line to be skipped this row is used as the coefficient
/// \return
vector<vector<long long>* > buildMat(vector<vector<long long>* > m,int index){
    vector<vector<long long>* > vec;
    for (int i=0;i<m.size();i++) {
        if(index==i){
            continue;
        }
            vec.push_back(m[i]);
    }
    return vec;
}
///
/// \param m - input matrix,this matrix is not squre,
/// \return determinant
long long determinantCalc(vector<vector<long long>* > m) {
    long long ret=0;
    long long inv=1;
    int endIndex=m[0]->size();  //the rows are not trimmed sot he matrix is not squred, this is used to calculate the
    // the amount of variables we need to skip in order to "squre the matrix"
    int matrixSize=m.size();
    if (matrixSize>2) {
        for (int i = 0; i < m.size(); ++i) {

            ret = ret+inv*(*m[i])[endIndex-matrixSize]*determinantCalc(buildMat(m,i));
            inv *= -1;
        }
    }
    if (matrixSize == 0) {
        return -1;
    }
    if (matrixSize == 1) {
        return (*m[endIndex-1])[endIndex-1];
    }
    if (m.size() == 2) {
        return (*m[0])[endIndex-2]*(*m[1])[endIndex-1]-(*m[0])[endIndex-1]*(*m[1])[endIndex-2];
    }
    return ret;
}
long long matrixDeterminant::determinant(vector<vector<long long> > m){
        if (m.size() == 0) {
            return -1;
        }
        vector<vector<long long>* > vec;
        for (int i=0;i<m.size();i++) {
            vec.push_back(&m[i]);
        }
        return determinantCalc(vec);
    }


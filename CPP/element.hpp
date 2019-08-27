//
// Created by David on 27-Aug-19.
//

#ifndef CPP_ELEMENT_HPP
#define CPP_ELEMENT_HPP

class element {
public:
    int weight;
    int row;
    int col;

    element(int row, int col, int weight) : row(row), col(col), weight(weight) {};

    ~element() {};

    element(const element &original) {
        row = original.row;
        col = original.col;
        weight = original.weight;
    }

    bool operator>(const element &y) const{
        return this->weight > y.weight;
    }

    bool operator<(const element &y) const {
        return this->weight < y.weight;
    }
};
#endif //CPP_ELEMENT_HPP

//
// Created by David on 24-Aug-19.
//

#include "katas.hpp"

// TODO: Determine whether one can reach the exit at (n - 1, n - 1)
// starting from (0, 0) in a n × n maze (represented as a string)
// and return a boolean value accordingly

///Wall is 1
/// path is 0
bool* string2Matrix(string maze, int colsize) {
    auto matrix = new bool[colsize * colsize];
    int row = 0;
    int col = 0;
    for (auto i:maze) {///filling the matrix, 1 for wall, 0 for path
        if (i == '/n') {
            row++;
            col = 0;
        } else {
            if (i == 'W')//wall
            {
                matrix[col + row * colsize] = true;
                col++;
            } else //i=='.'
            {
                matrix[col + row * colsize] = false;
                col++;
            }
        }
    }
    return matrix;
}

bool path(bool* maze, int row,int col, int n) {
    if (row == n - 1 && col == n - 1)///checking if we finished
        return true;
    if (row >= n || row < 0 || col >= n || col < 0)   /// making sure we stayed inbounds
        return false;
    if (maze[row * n + col] == 1) {///checking for walls
        return false;
    }
    maze[row * n + col] = 1;
    return path(maze, row, col + 1, n) || path(maze, row + 1, col, n)
        || path(maze, row, col - 1, n) || path(maze, row - 1, col, n);
}

bool PathFinderPart1::path_finder(string maze) {
    if (maze.empty()) {
        return true;
    }
    auto matrix = string2Matrix(maze, sqrt(maze.size()));
    bool ret=path(matrix,0,0,(int)sqrt(maze.size()));
delete(matrix);
    return ret;
}


/// empty is .
/// wall is W

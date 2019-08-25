//
// Created by David on 24-Aug-19.
//

#include "katas.hpp"
#include <assert.h>
// TODO: Determine whether one can reach the exit at (n - 1, n - 1)
// starting from (0, 0) in a n × n maze (represented as a string)
// and return a boolean value accordingly

bool PathFinderPart::test1() {
    /*
      Maze:
        .W.
        .W.
        ...
    */
    assert(path_finder1(".W.\n.W.\n...") == true);
    /*
      Maze:
        .W.
        .W.
        W..
    */
    assert(path_finder1(".W.\n.W.\nW..") == false);
    /*
      Maze:
        ......
        ......
        ......
        ......
        ......
        ......
    */
    assert(path_finder1("......\n......\n......\n......\n......\n......") == (true));
    /*
      Maze:
        ......
        ......
        ......
        ......
        .....W
        ....W.
    */
    assert(path_finder1("......\n......\n......\n......\n.....W\n....W.") == (false));
}
bool PathFinderPart::test2() {
    /*
      Maze:
        .W.
        .W.
        ...
    */
    assert(path_finder2(".W.\n.W.\n...") == 4);
    /*
      Maze:
        .W.
        .W.
        W..
    */
    assert(path_finder2(".W.\n.W.\nW..") == -1);
    /*
      Maze:
        ......
        ......
        ......
        ......
        ......
        ......
    */
    assert(path_finder2("......\n......\n......\n......\n......\n......") == (10));
    /*
      Maze:
        ......
        ......
        ......
        ......
        .....W
        ....W.
    */
    assert(path_finder2("......\n......\n......\n......\n.....W\n....W.") == (-1));
}


bool PathFinderPart::path(string& maze,int* matrix, int row,int col, int n,int distance) {
    if (row >= n || row < 0 || col >= n || col < 0)   /// making sure we stayed inbounds
        return false;
    if (maze[row * (n + 1) + col] == 'W') {///checking for walls
        return false;
    }
    if (maze[row * (n + 1) + col] == '.') {///first visit
        maze[row * (n + 1) + col] = '1';
        matrix[row *n + col]=distance;
    } else {
        if (matrix[row *n + col] <=distance){///already have shorter path
            return false;
        }
        matrix[row *n + col]=distance; ///updating with the current distance
    }
    if (row == (n - 1) && col == (n - 1)) {///checking if we finished
        return true;
    }
    bool direction[4];
    direction[0] = path(maze,matrix, row, col + 1, n, distance + 1);//right
    direction[1] = path(maze,matrix, row, col - 1, n, distance + 1);//left
    direction[2] = path(maze,matrix, row + 1, col, n, distance + 1);//down
    direction[3] = path(maze,matrix, row - 1, col, n, distance + 1);//up
    return direction[0] || direction[1]|| direction[2] || direction[3];
}

bool PathFinderPart::path_finder1(string maze) {
//    return path(maze, 0, 0, sqrt(maze.size()),0);
}
int PathFinderPart::path_finder2(string maze) {
    int n=sqrt(maze.size());
    int distanceMatrix[n*n];
    if (path(maze,distanceMatrix, 0, 0, n,0)==true){
        return distanceMatrix[n*n-1];
    }
    return -1;
}

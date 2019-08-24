//
// Created by David on 24-Aug-19.
//

#include "katas.hpp"
#include <assert.h>
// TODO: Determine whether one can reach the exit at (n - 1, n - 1)
// starting from (0, 0) in a n × n maze (represented as a string)
// and return a boolean value accordingly

bool PathFinderPart1::test(int x) {
    int y = 0;
    /*
      Maze:
        .W.
        .W.
        ...
    */
    assert(path_finder(".W.\n.W.\n...") == true);
    /*
      Maze:
        .W.
        .W.
        W..
    */
    assert(path_finder(".W.\n.W.\nW..") == false);
    /*
      Maze:
        ......
        ......
        ......
        ......
        ......
        ......
    */
    assert(path_finder("......\n......\n......\n......\n......\n......") == (true));
    /*
      Maze:
        ......
        ......
        ......
        ......
        .....W
        ....W.
    */
    assert(path_finder("......\n......\n......\n......\n.....W\n....W.") == (false));
    x=y;
}
///Wall is 1
/// path is 0

bool PathFinderPart1::path(string& maze, int row,int col, int n) {
    if (row == (n - 1) && col == (n - 1))///checking if we finished
        return true;
    if (row >= n || row < 0 || col >= n || col < 0)   /// making sure we stayed inbounds
        return false;
    if (maze[row * (n + 1) + col] == 'W') {///checking for walls
        return false;
    }
    maze[row * (n + 1) + col] = 'W';
    return path(maze, row, col + 1, n) || path(maze, row, col - 1, n)
           || path(maze, row + 1, col, n) || path(maze, row - 1, col, n);
}

bool PathFinderPart1::path_finder(string maze) {
    int i;
    for (i = 0; maze[i] !='\n' ; ++i) ;
    return path(maze,0,0,i);
    }

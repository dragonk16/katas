//
// Created by David on 24-Aug-19.
//
#include <queue>
#include "katas.hpp"
#include <assert.h>
#include "element.hpp"



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
bool PathFinderPart::test3() {
    std::string s1 =

            "000\n"
            "000\n"
            "000";

    std::string s2 =

            "010\n"
            "010\n"
            "010";

    std::string s3 =

            "010\n"
            "101\n"
            "010";

    std::string s4 =

            "0707\n"
            "7070\n"
            "0707\n"
            "7070";

    std::string s5 =

            "700000\n"
            "077770\n"
            "077770\n"
            "077770\n"
            "077770\n"
            "000007";

    std::string s6 =

            "777000\n"
            "007000\n"
            "007000\n"
            "007000\n"
            "007000\n"
            "007777";

    std::string s7 =

            "000000\n"
            "000000\n"
            "000000\n"
            "000010\n"
            "000109\n"
            "001010";

    assert(path_finder3(s1) == 0);
    assert(path_finder3(s2) == 2);
    assert(path_finder3(s3) == 4);
    assert(path_finder3(s4) == 42);
    assert(path_finder3(s5) == 14);
    assert(path_finder3(s6) == 0);
    assert(path_finder3(s7) == 4);

}


bool PathFinderPart::path(string& maze,int* matrix, int row,int col, int n,int distance) {
    enum directions{right,left,down,up};
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
    direction[right] = path(maze,matrix, row, col + 1, n, distance + 1);//right
    direction[left] = path(maze,matrix, row, col - 1, n, distance + 1);//left
    direction[down] = path(maze,matrix, row + 1, col, n, distance + 1);//down
    direction[up] = path(maze,matrix, row - 1, col, n, distance + 1);//up
    return direction[right] || direction[left]|| direction[down] || direction[up];
}
bool PathFinderPart::path_finder1(string maze) {
    int n=sqrt(maze.size());
    int distanceMatrix[n*n];
    return path(maze,distanceMatrix, 0, 0, n,0);
}
int PathFinderPart::path_finder2(string maze) {
    int n=sqrt(maze.size());
    int distanceMatrix[n*n];
    if (path(maze,distanceMatrix, 0, 0, n,0)==true){
        return distanceMatrix[n*n-1];
    }
    return -1;
}

int PathFinderPart::path_finder3(string maze) {
    int n = sqrt(maze.size());
    int matrix[n * n];
    for (int &i:matrix) {
        i = -1;
    }
    matrix[0] = 0;
    std::priority_queue<element,std::vector<element>,greater<element>> pq;///initialising a min heap
    pq.push(element (0,0,0));
    int currentElevation;
    int nextElevation = 0;
    int elevationsChange = 0;
    enum directions{left=0,right,down,up,current};
    for (element i=pq.top();pq.empty()!=1;i=pq.top(),pq.pop())
    {
        currentElevation = maze[i.row * (n + 1) + i.col] - '0';
        int coords[5] = {(i.row) * n + (i.col - 1), (i.row) * n + (i.col + 1),
                         (i.row + 1) * n + (i.col), (i.row - 1) * n + (i.col),
                         (i.row) * n + (i.col)};
        if (i.col < n - 1) {///going right
            nextElevation = maze[(i.row) * (n + 1) + (i.col + 1)] - '0';
            elevationsChange = abs(nextElevation - currentElevation);
            if (matrix[coords[right]] == -1 || matrix[coords[right]] > (elevationsChange + matrix[coords[current]])) {
                /// first visit or improvement
                matrix[coords[right]] = elevationsChange + matrix[coords[current]]; ///updating with the current distance
                pq.push(element(i.row, i.col + 1, matrix[coords[right]]));
            }
        }
        if (i.col > 0) {///going left
            nextElevation = maze[(i.row) * (n + 1) + (i.col - 1)] - '0';
            elevationsChange = abs(nextElevation - currentElevation);
            if (matrix[coords[left]] == -1 || matrix[coords[left]] > (elevationsChange + matrix[coords[current]])) {
                /// first visit or improvement
                matrix[coords[left]] = elevationsChange + matrix[coords[current]]; ///updating with the current distance
                pq.push(element(i.row, i.col - 1, matrix[coords[left]]));
            }
        }
        if (i.row > 0) {///going up
            nextElevation = maze[(i.row - 1) * (n + 1) + (i.col)] - '0';
            elevationsChange = abs(nextElevation - currentElevation);
            if (matrix[coords[up]] == -1 || matrix[coords[up]] > (elevationsChange + matrix[coords[current]])) {
                /// first visit or improvement
                matrix[coords[up]] = elevationsChange + matrix[coords[current]]; ///updating with the current distance
                pq.push(element(i.row - 1, i.col, matrix[coords[up]]));
            }
        }
        if (i.row < n - 1) {///going down
            nextElevation = maze[(i.row + 1) * (n + 1) + (i.col)] - '0';
            elevationsChange = abs(nextElevation - currentElevation);
            if (matrix[coords[down]] == -1 || matrix[coords[down]] > (elevationsChange + matrix[coords[current]])) {
                /// first visit or improvement
                matrix[coords[down]] = elevationsChange + matrix[coords[current]]; ///updating with the current distance
                pq.push(element(i.row + 1, i.col, matrix[coords[down]]));
            }
        }
    }
    return matrix[(n * n) - 1];
}
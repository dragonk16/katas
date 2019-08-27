//
// Created by David on 24-Aug-19.
//
#include <queue>
#include "katas.hpp"
#include <assert.h>
#include "element.hpp"


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

//bool PathFinderPart::path3(string& maze,int* matrix, int row,int col, int n,int previousElevation,int previuosPath) {
//    if (row >= n || row < 0 || col >= n || col < 0)   /// making sure we stayed inbounds
//        return false;
//    int currentElevation=maze[row * (n + 1) + col]-'0';
////    int elevationsChange=max(previousElevation-currentElevation,currentElevation-previousElevation);
//    int elevationsChange=abs(previousElevation-currentElevation);
//    if (matrix[row *n + col] != -1 && matrix[row *n + col] <= (elevationsChange+previuosPath) ) {///not first visit
//        // and no need to update
//            return false;
//        }
//    matrix[row *n + col]=elevationsChange+previuosPath; ///updating with the current distance
//    if (row == (n - 1) && col == (n - 1)) {///checking if we finished
//        return true;
//    }
//    bool direction[4];
//    direction[0] = path3(maze,matrix, row, col + 1, n, currentElevation, matrix[row *n + col]);//right
//    direction[1] = path3(maze,matrix, row, col - 1, n, currentElevation, matrix[row *n + col]);//left
//    direction[2] = path3(maze,matrix, row + 1, col, n, currentElevation, matrix[row *n + col]);//down
//    direction[3] = path3(maze,matrix, row - 1, col, n, currentElevation, matrix[row *n + col]);//up
//    return direction[0] || direction[1]|| direction[2] || direction[3];
//}

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
//int PathFinderPart::path_finder3(string maze) {
//    int n=sqrt(maze.size());
//    int distanceMatrix[n*n];
//    for (int &i:distanceMatrix){
//        i=-1;
//    }
//    if (path3(maze,distanceMatrix, 0, 0, n,maze[0]-'0',0)==true){
//        return distanceMatrix[(n*n)-1];
//    }
//    return -1;
//}


int PathFinderPart::path_finder3(string maze) {
    int n = sqrt(maze.size());
    int matrix[n * n];
    for (int &i:matrix) {
        i = -1;
    }
    matrix[0] = 0;
    std::priority_queue<element> pq;
    pq.push(element (0,0,0));
    int row;
    int col;
    int currentElevation;
    int nextElevation = 0;
    int elevationsChange = 0;
    for (element i=pq.top();pq.empty()!=1;i=pq.top()) {
        pq.pop();
        i.print();

        row = i.row;
        col = i.col;
        currentElevation = maze[row * (n + 1) + col] - '0';
        int coords[5] = {(row) * n + (col - 1), (row) * n + (col + 1), (row + 1) * n + (col), (row - 1) * n + (col),
                         (row) * n + (col)};
        ///0-left,1-right,2-down,3-up,4-current
        if (col < n - 1) {///going right-1
            nextElevation = maze[(row) * (n + 1) + (col + 1)] - '0';
            elevationsChange = abs(nextElevation - currentElevation);
            if (matrix[coords[1]] == -1 || matrix[coords[1]] > (elevationsChange + matrix[coords[4]])) {
                /// first visit or improvment
                matrix[coords[1]] = elevationsChange + matrix[coords[4]]; ///updating with the current distance
                pq.push(element(row, col + 1, matrix[coords[1]]));
            }
        }
        if (col > 0) {///going left-0
            nextElevation = maze[(row) * (n + 1) + (col - 1)] - '0';
            elevationsChange = abs(nextElevation - currentElevation);
            if (matrix[coords[0]] == -1 || matrix[coords[0]] > (elevationsChange + matrix[coords[4]])) {
                /// first visit or improvment
                matrix[coords[0]] = elevationsChange + matrix[coords[4]]; ///updating with the current distance
                pq.push(element(row, col - 1, matrix[coords[0]]));
            }
        }
        if (row > 0) {///going up-3
            nextElevation = maze[(row - 1) * (n + 1) + (col)] - '0';
            elevationsChange = abs(nextElevation - currentElevation);
            if (matrix[coords[3]] == -1 || matrix[coords[3]] > (elevationsChange + matrix[coords[4]])) {
                /// first visit or improvment
                matrix[coords[3]] = elevationsChange + matrix[coords[4]]; ///updating with the current distance
                pq.push(element(row - 1, col, matrix[coords[3]]));
            }
        }
        if (row < n - 1) {///going down-2
            nextElevation = maze[(row + 1) * (n + 1) + (col)] - '0';
            elevationsChange = abs(nextElevation - currentElevation);
            if (matrix[coords[2]] == -1 || matrix[coords[2]] > (elevationsChange + matrix[coords[4]])) {
                /// first visit or improvment
                matrix[coords[2]] = elevationsChange + matrix[coords[4]]; ///updating with the current distance
                pq.push(element(row + 1, col, matrix[coords[2]]));
            }
        }
    }
    return matrix[(n * n) - 1];
}
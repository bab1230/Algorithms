//
//  BFS.hpp
//  Lab2
//
//  Created by Braden Wallace on 9/26/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef BFS_hpp
#define BFS_hpp

#include <stdio.h>
#include "SearchAlgo.h"
#include <queue>
class BFS : public SearchAlgo{
public:
    BFS();
    virtual void searchList(std::vector<std::vector<Node>>& adjList, int start, int finish, bool isRecur, std::vector<bool> visited, Node* lastNode);
    virtual void searchMatrix(int** mat, int start, int finish, bool isRecur, std::vector<bool> visited, Node* lastNode);
//(Node**, int, int, std::vector<int>&, bool, std::vector<bool>, Node* lastNode)
//(Node**, int, int, std::vector<int>&, bool, std::vector<bool> visited);
private:
    void BFSrecurHelper(std::vector<std::vector<Node>>& adjList, int start, int finish, std::vector<bool> visited);
};
#endif /* BFS_hpp */

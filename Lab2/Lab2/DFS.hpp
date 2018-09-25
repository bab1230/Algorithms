//
//  DFS.hpp
//  Lab2
//
//  Created by Braden Wallace on 9/24/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef DFS_hpp
#define DFS_hpp

#include <stdio.h>
#include "SearchAlgo.h"
class DFS : public SearchAlgo{
public:
    DFS();
    virtual void searchList(std::vector<std::list<Node>>& adjList, int start, int finish, bool isRecur = false, std::vector<bool> visited = {});
    virtual void searchMatrix(int** mat, int start, int finish, bool isRecur = false);
};
#endif /* DFS_hpp */

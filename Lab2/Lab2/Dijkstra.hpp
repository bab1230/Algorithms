//
//  Dijkstra.hpp
//  Lab2
//
//  Created by Braden Wallace on 9/26/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef Dijkstra_hpp
#define Dijkstra_hpp

#include <stdio.h>
#include "SearchAlgo.h"
class Dijkstra : public SearchAlgo{
public:
    Dijkstra();
    virtual void searchList(std::vector<std::vector<Node>>& adjList, int start, int finish, std::vector<int>& path);
    virtual void searchMatrix(Node** mat, int start, int finish, std::vector<int>& path);
};
#endif /* Dijkstra_hpp */

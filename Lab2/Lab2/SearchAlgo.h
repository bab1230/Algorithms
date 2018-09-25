//
//  SearchAlgo.h
//  Lab2
//
//  Created by Braden Wallace on 9/13/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef SearchAlgo_h
#define SearchAlgo_h
#include <vector>
#include <list>
class SearchAlgo {
public:
    struct Node {
        int data = 0;
        double distance= 0.0;
        //bool visited = false;
        int weight = 0;
    };
    virtual void searchList(std::vector<std::list<Node>>&, int, int, bool = false, std::vector<bool> = {}) = 0;
    virtual void searchMatrix(int**, int, int, bool = false) = 0;
    
};

#endif /* SearchAlgo_h */

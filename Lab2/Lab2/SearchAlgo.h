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
        Node* nextPtr = NULL;
        //Node* prevPointer = nullptr;
    };
    virtual void searchList(std::vector<std::vector<Node>>&, int, int, std::vector<int>&, bool, std::vector<bool>, Node*) = 0;
    virtual void searchMatrix(int**, int, int, std::vector<int>&, bool, std::vector<bool>, Node* lastNode) = 0;
    
};

#endif /* SearchAlgo_h */

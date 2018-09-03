//
//  SortingAlgo.h
//  Lab1
//
//  Created by Braden Wallace on 8/29/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef SortingAlgo_h
#define SortingAlgo_h
#include <vector>
class SortingAlgo{
public:
    virtual void sort(std::vector<int>&){};
    virtual void swap(int*, int*){};
    virtual void BinaryTree(){};//vector thing)
private:
    static void BinaryTreeSort(std::vector<int>&, int index){};
};

#endif /* SortingAlgo_h */

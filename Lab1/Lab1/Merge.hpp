//
//  Merge.hpp
//  Lab1
//
//  Created by Braden Wallace on 8/29/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef Merge_hpp
#define Merge_hpp

#include <stdio.h>
#include "SortingAlgo.h"
class Merge : public SortingAlgo{
private:
    std::vector<int> mergeSort(std::vector<int> left, std::vector<int> right);
public:
    virtual void sort(std::vector<int>&);
    virtual void swap(int*, int*);
};
#endif /* Merge_hpp */

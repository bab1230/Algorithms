//
//  Bubble.hpp
//  Lab1
//
//  Created by Braden Wallace on 8/29/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef Bubble_hpp
#define Bubble_hpp
#include "SortingAlgo.h"
#include <stdio.h>
class Bubble : public SortingAlgo{
public:
    virtual void sort(std::vector<int>&);
    virtual void swap(int*, int*);
};
#endif /* Bubble_hpp */

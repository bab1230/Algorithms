//
//  Insertion.hpp
//  Lab1
//
//  Created by Braden Wallace on 8/29/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef Insertion_hpp
#define Insertion_hpp

#include <stdio.h>
#include "SortingAlgo.h"
class Insertion : public SortingAlgo{
public:
    virtual void sort(std::vector<int>&);
    virtual void swap(int*, int*);
};
#endif /* Insertion_hpp */

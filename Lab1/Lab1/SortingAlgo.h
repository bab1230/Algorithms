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
template <typename T>
class SortingAlgo{
public:
    virtual void sort(std::vector<T>&) = 0;
    virtual void swap(T*, T*) = 0;
};

#endif /* SortingAlgo_h */

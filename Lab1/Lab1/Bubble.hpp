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
template <typename T>
class Bubble : public SortingAlgo<T>{
public:
    virtual void sort(std::vector<T>&);
    virtual void swap(T*, T*);
};
template <typename T>
void Bubble<T>::sort(std::vector<T>& data){
    for (int i = 0; i < data.size()-1; i++)
        for (int j = 0; j < data.size()-i-1; j++)
            if (data[j] > data[j+1])
                swap(&data[j], &data[j+1]);
}
template <typename T>
void Bubble<T>::swap(T* aPtr, T* bPtr){
    T temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}
#endif /* Bubble_hpp */

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
template <typename T>
class Insertion : public SortingAlgo<T>{
public:
    virtual void sort(std::vector<T>&);
    virtual void swap(T*, T*);
};
template <typename T>
void Insertion<T>::sort(std::vector<T>& data){
    for (int i = 1; i < data.size(); i++) {
        for (int j = i; j > 0 && data[j - 1] > data[j]; j--)
            swap(&data[j], &data[j-1]);
    }
}
template <typename T>
void Insertion<T>::swap(T* aPtr, T* bPtr){
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}
#endif /* Insertion_hpp */

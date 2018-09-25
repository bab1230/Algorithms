//
//  Merge.hpp
//  Lab2
//
//  Created by Braden Wallace on 8/29/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef Merge_h
#define Merge_h

#include <stdio.h>
#include "SortingAlgo.h"
template <typename T>
class Merge : public SortingAlgo<T>{
private:
    std::vector<T> mergeSort(std::vector<T> left, std::vector<T> right);
public:
    virtual void sort(std::vector<T>&);
    virtual void swap(T*, T*);
};

template <typename T>
void Merge<T>::sort(std::vector<T>& data){
    
    if (data.size() <= 1)
        return;
    
    std::vector<T> left, right;
    int middle = ((int)data.size()+ 1) / 2;
    
    left = std::vector<T>(data.begin(), data.begin() + middle);
    right = std::vector<T>(data.begin() + middle, data.end());
    
    sort(left);
    sort(right);
    data = mergeSort(left, right);
}
template <typename T>
std::vector<T> Merge<T>::mergeSort(std::vector<T> left, std::vector<T> right){
    std::vector<T> result;
    while (left.size() || right.size()) {
        if (left.size() && right.size()) {
            if (left[0] <= right[0]) {
                result.push_back(left[0]);
                left.erase(left.begin());
            }
            else {
                result.push_back(right[0]);
                right.erase(right.begin());
            }
        }  else if (left.size()) {
            result.insert(result.end(), left.begin(), left.end());
            break;
        }  else if (right.size()) {
            result.insert(result.end(), right.begin(), right.end());
            break;
        }
    }
    return result;
}
template <typename T>
void Merge<T>::swap(T* aPtr, T* bPtr){
    T temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}
#endif /* Merge_h */

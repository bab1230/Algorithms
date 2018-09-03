//
//  Merge.cpp
//  Lab1
//
//  Created by Braden Wallace on 8/29/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#include "Merge.hpp"
#include <iostream>
void Merge::sort(std::vector<int>& data){
    
    if (data.size() <= 1)
        return;
    
    std::vector<int> left, right;
    int middle = ((int)data.size()+ 1) / 2;
    
    left = std::vector<int>(data.begin(), data.begin() + middle);
    right = std::vector<int>(data.begin() + middle, data.end());
    
    sort(left);
    sort(right);
    data = mergeSort(left, right);
}
std::vector<int> Merge::mergeSort(std::vector<int> left, std::vector<int> right){
    std::vector<int> result;
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
void Merge::swap(int* aPtr, int* bPtr){
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}

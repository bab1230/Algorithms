//
//  Insertion.cpp
//  Lab1
//
//  Created by Braden Wallace on 8/29/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#include "Insertion.hpp"
#include <iostream>
void Insertion::sort(std::vector<int>& data){
    for (int i = 1; i < data.size(); i++) {
        for (int j = i; j > 0 && data[j - 1] > data[j]; j--)
            swap(&data[j], &data[j-1]);
    }
}
void Insertion::swap(int* aPtr, int* bPtr){
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}

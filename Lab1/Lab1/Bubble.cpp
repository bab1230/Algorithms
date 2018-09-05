//
//  Bubble.cpp
//  Lab1
//
//  Created by Braden Wallace on 8/29/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#include "Bubble.hpp"
#include <iostream>
void Bubble::sort(std::vector<int>& data){
    for (int i = 0; i < data.size()-1; i++)
        for (int j = 0; j < data.size()-i-1; j++)
            if (data[j] > data[j+1])
                swap(&data[j], &data[j+1]);
}
void Bubble::swap(int* aPtr, int* bPtr){
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}

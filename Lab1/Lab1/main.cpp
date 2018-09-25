//
//  main.cpp
//  Lab1
//
//  Created by Braden Wallace on 8/28/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#include <iostream>
#include "Bubble.hpp"
#include "Insertion.hpp"
#include "Merge.hpp"
#include "Sort.hpp"
#include "GenerateData.hpp"
#include "AlgoFactory.hpp"
void swap(int* aPtr, int* bPtr){
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}
const std::vector<std::string> dataOrders = {"Reverse", "Random", "Random30percent", "Unique"};
const std::vector<std::string> dataSizes = {"10.txt","1000.txt","10000.txt","100000.txt"};

int main(int argc, const char * argv[]) {
    Sort* factoryAlgo = (Sort*)(AlgoFactory::Create(AlgoFactory::SEARCH));
    
    factoryAlgo->setExcecutionType(Sort::Configuration exe)
    return 0;
}

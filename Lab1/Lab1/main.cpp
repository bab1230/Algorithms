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
#include <vector>
#include <string>
void swap(int* aPtr, int* bPtr){
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}
const std::vector<std::string> dataOrders = {"Reverse", "Random", "Random30percent", "Unique"};
const std::vector<std::string> dataSizes = {"10.txt","1000.txt","10000.txt","100000.txt"};

int main(int argc, const char * argv[]) {
    GenerateData b;
    b.generate();
    
    Algorithm* sort;
    for(int i = 0; i <= 2; i++){
        AlgoType algo = static_cast<AlgoType>(i);
        for(int j = 0; j < dataOrders.size(); j++){
            for(int k = 0; k < dataSizes.size(); k++){
                std::string fileName = dataOrders[j] + dataSizes[k];
                sort = new Sort();
                sort->load(fileName);
                sort->select(algo);
                sort->excecute();
                sort->stats();
                sort->save("Sorted");
            }
        }
    }
    return 0;
}

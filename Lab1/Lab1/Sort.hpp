//
//  Sort.hpp
//  Lab1
//
//  Created by Braden Wallace on 8/28/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//
#include "Algorithm.hpp"
#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>
#include "SortingAlgo.h"
class Sort : public Algorithm{

public:
    Sort();
    void load(std::string);//Takes a filename as and can read input data file
    void excecute();//Executes the search algorithm
    void display();//Prints solution to screen
    void stats();//Prints algorithm name, execution time and number of records analyzed to screen in a readable format
    void select(AlgoType);//enum or int or id passed as input and loads corresponding algorithm to interface
    void save(std::string);//Saves solution to file path given as input
    void configure();//Future expandability
    
    //Builder
    enum Configuration {
        RECURSIVE = 0,
        ITERATIVE,
        LIST,
        MATRIX
    };
    
    void setExcecutionType(Sort::Configuration exe);
    void setStorageType(Sort::Configuration stg);
    
    void getConfiguration();
private:
    static SortingAlgo<int>* algorithm;
    
    Sort::Configuration excecutionType;
    Sort::Configuration storageType;
    
};

#endif /* Sort_hpp */

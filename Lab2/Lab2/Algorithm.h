//
//  Algorithm.hpp
//  Lab2
//
//  Created by Braden Wallace on 8/28/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef Algorithm_hpp
#define Algorithm_hpp
#include <vector>
#include <stdio.h>
#include <chrono>
#include <string>
#include "Bubble.h"
#include "Insertion.h"
#include "Merge.h"
#include "SortingAlgo.h"
#include "SearchAlgo.h"
enum AlgoType{
    BUBBLE = 0,
    INSERTION = 1,
    MERGE = 2,
    DFS = 3,
    BFS = 4,
    DIJKSTRA = 5,
    ASTAR = 6,
    FINISH = 7
};
class Algorithm{
protected:
    std::vector<int> data;
    SortingAlgo<int>* selectedAlgo;
    SearchAlgo* searchAlgo;
    double time;
    std::string algoName;
    std::string dataType;
public:
    virtual void load(std::string, std::string = 0, std::string = 0) = 0;//Takes a filename as and can read input data file]
    virtual void excecute() = 0;//Executes the search algorithm
    virtual void display() = 0;//Prints solution to screen
    virtual void stats() = 0;//Prints algorithm name, execution time and number of records analyzed to screen in a readable format
    virtual void select(AlgoType) = 0;//enum or int or id passed as input and loads corresponding algorithm to interface
    virtual void save(std::string) = 0;//Saves solution to file path given as input]
    virtual void configure() = 0;//Future expandability
};

#endif /* Algorithm_hpp */

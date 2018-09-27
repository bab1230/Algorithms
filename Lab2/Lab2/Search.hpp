//
//  Search.hpp
//  Lab2
//
//  Created by Braden Wallace on 9/11/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef Search_hpp
#define Search_hpp
#include "Algorithm.h"
#include "SearchAlgo.h"
#include <stdio.h>
#include <vector>
#include <list>
class Search : public Algorithm{
public:
    
    Search();
    void load(std::string, std::string, std::string);//Takes a filename as and can read input data file
    void excecute();//Executes the search algorithm
    void display();//Prints solution to screen
    void stats();//Prints algorithm name, execution time and number of records analyzed to screen in a readable format
    void select(AlgoType);//enum or int or id passed as input and loads corresponding algorithm to interface
    void save(std::string);//Saves solution to file path given as input
    void configure();//Future expandability
private:
    static SearchAlgo* algorithm;
    std::vector<std::vector<SearchAlgo::Node>> adjacencyList;
    int** adjacencyMatrix;
};
#endif /* Search_hpp */

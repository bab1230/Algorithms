//
//  main.cpp
//  Lab1
//
//  Created by Braden Wallace on 8/28/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#include <iostream>
#include "Bubble.h"
#include "Insertion.h"
#include "Merge.h"
#include "Sort.hpp"
#include "GenerateData.h"
#include "Search.hpp"
int main(int argc, const char * argv[]) {
    int start = 1;
    int finish = 14;
    Algorithm* algo = new Search();
    if(argc >= 3) {
        start = std::stoi(argv[1]);
        finish = std::stoi(argv[2]);
    }
    algo->load("graph.txt", "weights.txt", "positions.txt");
    algo->select(DFS);
    algo->excecute(start, finish, false, true);
    algo->stats();
    algo->clear();
    
    algo->load("graph.txt", "weights.txt", "positions.txt");
    algo->select(DFS);
    algo->excecute(start, finish, true, true);
    algo->stats();
    algo->clear();
    
    algo->load("graph.txt", "weights.txt", "positions.txt");
    algo->select(DFS);
    algo->excecute(start, finish, false, false);
    algo->stats();
    algo->clear();
    
    algo->load("graph.txt", "weights.txt", "positions.txt");
    algo->select(DFS);
    algo->excecute(start, finish, true, false);
    algo->stats();
    algo->clear();
    
    algo->load("graph.txt", "weights.txt", "positions.txt");
    algo->select(BFS);
    algo->excecute(start, finish, false, true);
    algo->stats();
    algo->clear();
    
    algo->load("graph.txt", "weights.txt", "positions.txt");
    algo->select(BFS);
    algo->excecute(start, finish, false, false);
    algo->stats();
    algo->clear();
    return 0;
}

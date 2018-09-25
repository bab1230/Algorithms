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
    Search b;
    b.load("graph.txt", "weights.txt", "positions.txt");
    b.select(DFS);
    b.excecute();
    return 0;
}

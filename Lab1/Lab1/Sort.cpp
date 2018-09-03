//
//  Sort.cpp
//  Lab1
//
//  Created by Braden Wallace on 8/28/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//
#include <fstream>
#include <iostream>
#include "Sort.hpp"
using namespace std;
Sort::Sort(){
    
}
void Sort::load(char* fileName){
    ifstream file;
    file.open(fileName);
    if (!file) {
        cerr << "Unable to open file";
        exit(1);
    }
    while(!file.eof()){
        int number;
        file >> number;
        data.push_back(number);
    }
    file.close();
}
void Sort::excecute(){
    selectedAlgo.sort(data);
    for(int x: data)
        std::cout << x << std::endl;
}
void Sort::display(){
    
}
void Sort::stats(){
    
}
void Sort::select(AlgoType algo){
    if(algo == 0)
        selectedAlgo = Bubble();
    else if(algo == 1)
        selectedAlgo = Insertion();
    else if(algo == 2)
        selectedAlgo = Merge();
}
void Sort::save(char * fileName){
    
}
void Sort::configure(){
    
}

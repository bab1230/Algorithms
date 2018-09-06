//
//  Sort.cpp
//  Lab1
//
//  Created by Braden Wallace on 8/28/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//
#include <fstream>
#include <iostream>
#include <string>
#include "Sort.hpp"
using namespace std;
Sort::Sort(){
    
}
void Sort::load(std::string fileName){
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
    auto start = std::chrono::high_resolution_clock::now();
    selectedAlgo->sort(data);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    time = elapsed.count();
}
void Sort::display(){
    for(int x: data){
        cout << x << endl;
    }
}
void Sort::stats(){
    cout << "Algorithm Name: " << algoName << endl;
    cout << "Excecution Time: " << time << endl;
    cout << "Number of Records Analyzed: " << data.size() << endl << endl;
}
void Sort::select(AlgoType algo){
    if(algo == 0){
        selectedAlgo = new Bubble();
        algoName = "bubble";
    }
    else if(algo == 1){
        selectedAlgo = new Insertion();
        algoName = "insertion";
    }
    else if(algo == 2){
        selectedAlgo = new Merge();
        algoName = "merge";
    }
}
void Sort::save(char * fileName){
    ofstream file;
    file.open(fileName);
    if (!file) {
        cerr << "Unable to open file";
        exit(1);
    }
    for(int i = 0; i <data.size();i++)
        file << data[i] << endl;
    file.close();
}
void Sort::configure(){
    
}

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
Sort::Sort(){
    
}
void Sort::load(std::string fileName){
    dataType = fileName.substr(0, fileName.find("1"));
    std::ifstream file;
    file.open("TestData/" + fileName);
    if (!file) {
        std::cerr << "Unable to open file";
        exit(1);
    }
    int number;
    while(file >> number){
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
        std::cout << x << std::endl;
    }
}
void Sort::stats(){
    std::cout << "Algorithm Name: " << algoName << std::endl;
    std::cout << "Excecution Time: " << time << std::endl;
    std::cout << "Data Type : " << dataType << std::endl;
    std::cout << "Number of Records Analyzed: " << data.size() << std::endl << std::endl;
}
void Sort::select(AlgoType algo){
    if(algo == 0){
        selectedAlgo = new Bubble<int>();
        algoName = "bubble";
    }
    else if(algo == 1){
        selectedAlgo = new Insertion<int>();
        algoName = "insertion";
    }
    else if(algo == 2){
        selectedAlgo = new Merge<int>();
        algoName = "merge";
    }
}
void Sort::save(std::string fileName){
    std::ofstream outFile;
    std::string filepath = "Saves/" + fileName + dataType + std::to_string(data.size()) + algoName + ".txt";
    outFile.open(filepath);
    if (!outFile) {
        std::cerr << "Unable to open file";
        exit(1);
    }
    for(int i = 0; i <data.size();i++)
        outFile << data[i] << std::endl;
    outFile.close();
}
void Sort::configure(){
    
}

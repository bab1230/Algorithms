//
//  Search.cpp
//  Lab2
//
//  Created by Braden Wallace on 9/11/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#include "Search.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include "DFS.hpp"
#include "BFS.hpp"
struct find_data : std::unary_function<SearchAlgo::Node, bool> {
    int data;
    find_data(int data):data(data) { }
    bool operator()(SearchAlgo::Node const& node) const {
        return node.data == data;
    }
};
Search::Search(){
    
}
void Search::load(std::string graphFile, std::string weightsFile, std::string positionsFile){
    std::ifstream graph(graphFile);
    if(!graph){
        std::cerr << "CANNOT OPEN FILE" << std::endl;
        exit(1);
    }
    std::ifstream weights(weightsFile);
    if(!weights){
        std::cerr << "CANNOT OPEN FILE" << std::endl;
        exit(1);
    }
    std::ifstream positions(positionsFile);
    if(!positions){
        std::cerr << "CANNOT OPEN FILE" << std::endl;
        exit(1);
    }
    std::string temp;
    std::string line;
    while(graph >> line){
        SearchAlgo::Node a;
        std::vector<SearchAlgo::Node> graphLine;
        std::stringstream seperate(line);

        while(getline(seperate, temp, ',')) {
            a.data = std::stoi(temp);
            graphLine.push_back(a);
        }
        adjacencyList.push_back(graphLine);
    }
    
    int size = 0;
    while(positions >> line) {
        std::stringstream seperate(line);
        std::getline(seperate, temp, ',');
        
        int dist = 0;
        for(int i = 0; i < 3; i++) {
            std::getline(seperate, temp, ',');
            dist += std::stoi(temp)*std::stoi(temp);
        }
        adjacencyList[size].front().distance = dist;
        size++;
    }
    
    for(int i = 0; i < adjacencyList.size(); i++){
        std::vector<SearchAlgo::Node>::iterator begin = adjacencyList[i].begin();
        for (std::vector<SearchAlgo::Node>::iterator it = ++adjacencyList[i].begin(); it != adjacencyList[i].end(); it++){
            std::vector<SearchAlgo::Node>::iterator firstNew = adjacencyList[it->data-1].begin();
            it->distance = (firstNew->distance - begin->distance) * (firstNew->distance - begin->distance);
        }
    }
    
    while(weights >> line){
        std::stringstream seperate(line);
        std::getline(seperate, temp, ',');
        std::string one = temp;
        std::getline(seperate, temp, ',');
        std::string two = temp;
        
        std::getline(seperate, temp, ',');
        std::string weight = temp;

        for(SearchAlgo::Node& n: adjacencyList[std::stoi(one)-1]) {
            if (n.data == std::stoi(two)) {
                n.weight = std::stoi(weight);
            }
        }
    }
    graph.clear();
    graph.seekg(0, std::ios::beg);
    
    adjacencyMatrix = new int*[adjacencyList.size()];
    for(int i =0; i < adjacencyList.size(); i++) {
        adjacencyMatrix[i] = new int[adjacencyList.size()];
    }
    for(size_t i = 0; i < adjacencyList.size(); i++)
        for(size_t j = 0; j < adjacencyList.size(); j++)
            adjacencyMatrix[i][j] = 0;
        
    //std::fill(adjacencyMatrix[0], adjacencyMatrix[0] + adjacencyList.size()*adjacencyList.size(), 0);

    while(graph >> line){
        std::stringstream seperate(line);
        std::getline(seperate, temp, ',');//this is the row
        int row = std::stoi(temp);
        while(std::getline(seperate, temp, ','))
            adjacencyMatrix[row-1][std::stoi(temp)-1] = 1;
    }
}
void Search::excecute(){
    std::vector<int> iterPath;
    std::vector<int> recurPath;
    std::vector<bool> visited(adjacencyList.size(), false);
    
    //recursive searvh
    /*searchAlgo->searchList(adjacencyList, 1, 16, recurPath, true, visited, &adjacencyList[0].front());
    DFS::Node buff = adjacencyList[0].front();
    while(buff.nextPtr){
        std::cout << buff.data << " ";
        buff = *buff.nextPtr;
    }
    
    //clears next pointers
    DFS::Node* clear = &adjacencyList[0].front();
    DFS::Node* temp = clear->nextPtr;
    while(clear->nextPtr){
        clear->nextPtr = nullptr;
        clear = temp;
    }*/
    
    //searchAlgo->searchList(adjacencyList, 1, 16, iterPath, false, visited, &adjacencyList[0].front());
    searchAlgo->searchMatrix(adjacencyMatrix, 1, 16, iterPath, false, visited, &adjacencyList[0].front());
    
//    for(auto i: iterPath) {
//        std::cout << i << " ";
//    }
    
    std::cout << std::endl << std::endl;
    DFS::Node buff = adjacencyList[0].front();
    while(buff.nextPtr){
        std::cout << buff.data << " ";
        buff = *buff.nextPtr;
    }
    std::cout << buff.data << std::endl;
    /*std::cout << "Iterative Path: ";
    for(auto i: iterPath)
        std::cout << i << " ";
    std::cout << std::endl;
    
    std::cout << "Recursive Path: ";
    for(auto i: recurPath)
        std::cout << i << " ";
    std::cout << std::endl;*/
}
void Search::display(){
    
}
void Search::stats(){
    
}
void Search::select(AlgoType algo){
    switch(algo){
            break;
        case DFS:
            searchAlgo = new class DFS();
            break;
        case BFS:
            searchAlgo = new class BFS();
            break;
        case DIJKSTRA:
            //selectedAlgo = new Dijikstra();
            break;
        case ASTAR:
            //selectedAlgo = new Astar();
            break;
        default:
            break;
    }
}
void Search::save(std::string fileName){
    
}
void Search::configure(){
    
}

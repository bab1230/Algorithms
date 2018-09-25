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
        std::list<SearchAlgo::Node> graphLine;
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
        dist = sqrt(dist);
        adjacencyList[size].front().distance = dist;
        size++;
    }
    
    for(int i = 0; i < adjacencyList.size(); i++){
        std::list<SearchAlgo::Node>::iterator begin = adjacencyList[i].begin();
        for (std::list<SearchAlgo::Node>::iterator it = ++adjacencyList[i].begin(); it != adjacencyList[i].end(); it++){
            std::list<SearchAlgo::Node>::iterator firstNew = adjacencyList[it->data-1].begin();
            it->distance = firstNew->distance - begin->distance;
        }
    }
}
void Search::excecute(){
    std::vector<bool> visited(adjacencyList.size(), false);
    searchAlgo->searchList(adjacencyList, 1, 16, true, visited);
    std::cout << std::endl;
    searchAlgo->searchList(adjacencyList, 1, 16, false, visited);
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
            //selectedAlgo = new BFS();
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

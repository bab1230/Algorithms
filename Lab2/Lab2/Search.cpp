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
    

    while(graph >> line){
        std::stringstream seperate(line);
        std::getline(seperate, temp, ',');//this is the row
        int row = std::stoi(temp);
        while(std::getline(seperate, temp, ','))
            adjacencyMatrix[row-1][std::stoi(temp)-1] = 1;
    }
}
void Search::excecute(int start, int finish, bool isRecur, bool isList){
    std::vector<bool> visited(adjacencyList.size(), false);
    auto startTime = std::chrono::high_resolution_clock::now();
    if(isList)
        searchAlgo->searchList(adjacencyList, start, finish, isRecur, visited, &adjacencyList[0].front());
    else
        searchAlgo->searchMatrix(adjacencyMatrix, start, finish, isRecur, visited, &adjacencyList[0].front());
    auto finishTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finishTime - startTime;
    time = elapsed.count();
    if(isRecur)
        algoName += "Recursive ";
    else
        algoName += "Iterative ";
    if(isList)
        algoName += "Adjacency List";
    else
        algoName += "Adjacency Matrix";
    
    DFS::Node buff = adjacencyList[0].front();
    while(buff.nextPtr){
        returnedPath += std::to_string(buff.data) + " ";
        distance += sqrt(buff.distance);
        buff = *buff.nextPtr;
    }
    returnedPath += std::to_string(buff.data) + " ";
    distance += sqrt(buff.distance);
}
void Search::display(){
    
}
void Search::stats(){
    std::cout << "Algorithm Name: " << algoName << std::endl;
    std::cout << "Path: " << returnedPath << std::endl;
    std::cout << "Distance: " << distance << std::endl;
    std::cout << "Number of nodes explored: " << searchAlgo->nodesExplored << std::endl;
    std::cout << "Excecution time: " << time << " seconds" << std::endl << std::endl;
    
}
void Search::select(AlgoType algo){
    switch(algo){
            break;
        case DFS:
            searchAlgo = new class DFS();
            algoName += "DFS ";
            break;
        case BFS:
            searchAlgo = new class BFS();
            algoName += "BFS ";
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
void Search::clear() {
    for(int i = 0; i < adjacencyList.size(); i++)
        delete [] adjacencyMatrix[i];
    delete [] adjacencyMatrix;
    for(auto i: adjacencyList)
        i.clear();
    adjacencyList.clear();
    path.clear();
    returnedPath = "";
    algoName = "";
    searchAlgo->nodesExplored = 0;
    distance = 0;
}

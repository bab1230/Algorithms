//
//  DFS.cpp
//  Lab2
//
//  Created by Braden Wallace on 9/24/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#include "DFS.hpp"
#include <stack>
#include <iostream>
DFS::DFS(){
    
}
void DFS::searchList(std::vector<std::list<Node> > &adjList, int start, int finish, bool isRecur, std::vector<bool> visited){
    if(!isRecur){
        std::stack<Node> stack;
        std::list<Node>::iterator it = adjList[start-1].begin();
        
        stack.push(*it);
        visited[start-1] = true;
        
        while(stack.size()){
            Node node = stack.top();
            stack.pop();
            
            for(it = ++adjList[node.data-1].begin(); it != adjList[node.data-1].end(); it++){
                if(it->data == finish)
                    return;
                std::list<Node>::iterator nodeVisit = adjList[it->data-1].begin();
                if(!visited[nodeVisit->data-1]){
                    visited[nodeVisit->data-1] = true;
                    stack.push(*it);
                    std::cout << std::to_string(nodeVisit->data) + " ";
                }
            }
        }
    } else {
        
        if(start == finish)
            return;
        visited[start-1] = true;
        for(std::list<Node>::iterator it = ++adjList[start-1].begin(); it != adjList[start-1].end(); it++) {
            if(!visited[it->data-1]) {
                std::cout << std::to_string(it->data) + " ";
                searchList(adjList, it->data, finish, true, visited);
            }
        }
    }
}
void DFS::searchMatrix(int **mat, int start, int finish, bool isRecur){
    
}

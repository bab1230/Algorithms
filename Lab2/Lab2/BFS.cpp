//
//  BFS.cpp
//  Lab2
//
//  Created by Braden Wallace on 9/26/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#include "BFS.hpp"
#include <iostream>
BFS::BFS(){
    
}
void BFS::searchList(std::vector<std::vector<Node> > &adjList, int start, int finish, std::vector<int>& path, bool isRecur, std::vector<bool> visited, Node* lastNode){
    if(!isRecur){
        std::queue<Node> myQueue;
        std::vector<Node>::iterator it = adjList[start-1].begin();
        myQueue.push(*it);
        visited[start-1] = true;
        
        while(myQueue.size()){
            Node node = myQueue.front();
            myQueue.pop();
            
            for(it = adjList[node.data-1].begin()+1; it != adjList[node.data-1].end(); it++){
                if(it->data == finish)
                    return;
                std::vector<Node>::iterator nodeVisit = adjList[it->data-1].begin();
                if(!visited[(*it).data-1]){
                    path.push_back((*it).data);
                    lastNode->nextPtr = &*it;
                    visited[nodeVisit->data-1] = true;
                    myQueue.push(*it);
                    lastNode = &*it;
                }
            }
        }
    } else {
        //1 2 5 6 9 10 13 14 15
        if(start == finish)
            return;
        visited[start-1] = true;
        for(std::vector<Node>::iterator it = adjList[start-1].begin()+1; it != adjList[start-1].end(); it++) {
            if(!visited[it->data-1]) {
                path.push_back(it->data);
                visited[it->data-1] = true;
                lastNode->nextPtr = &*it;
                searchList(adjList, it->data, finish, path, true, visited, &*it);
            }
        }
    }
}

void BFS::searchMatrix(int **mat, int start, int finish,std::vector<int>& path, bool isRecur, std::vector<bool> visited, Node* lastNode) {
    if(!isRecur) {
        
    } else {
        if(start == finish){
            path.push_back(start);
            return;
        }
        for(int i=0; i < sizeof mat/sizeof mat[0]; i++)
            if(!visited[start-1]&&mat[start-1][i]==1){
                path.push_back(i+1);
                searchMatrix(mat, i+1, finish, path, true, visited, lastNode);
            }
    }
}

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
void BFS::searchList(std::vector<std::vector<Node> > &adjList, int start, int finish, bool isRecur, std::vector<bool> visited, Node* lastNode){
    if(!isRecur){
        std::queue<Node> myQueue;
        std::vector<Node>::iterator it = adjList[start-1].begin();
        myQueue.push(*it);
        visited[start-1] = true;
        
        while(myQueue.size()){
            Node node = myQueue.front();
            myQueue.pop();
            
            for(it = adjList[node.data-1].begin()+1; it != adjList[node.data-1].end(); it++){
                if(it->data == finish){
                    nodesExplored++;
                    lastNode->nextPtr = new Node();
                    lastNode->nextPtr->data = it->data;
                    return;
                }
                std::vector<Node>::iterator nodeVisit = adjList[it->data-1].begin();
                if(!visited[(*it).data-1]){
                    nodesExplored++;
                    lastNode->nextPtr = &*it;
                    visited[nodeVisit->data-1] = true;
                    myQueue.push(*it);
                    lastNode = &*it;
                }
            }
        }
    } else {
        
    }
}

void BFS::searchMatrix(int **mat, int start, int finish, bool isRecur, std::vector<bool> visited, Node* lastNode) {
    if(!isRecur) {
        std::queue<int> myQueue;
        int val = start;
        myQueue.push(val);
        visited[start-1] = true;
        while(myQueue.size()){
            int node = myQueue.front();
            myQueue.pop();
            
            for(int i=node-1; i < finish; i++){//figure out what to make range
                if(node == finish){
                    nodesExplored++;
                    return;
                }
                if(mat[node-1][i] != 0 && !visited[i] && node-1 != i){
                    if (!visited[i]) {
                        nodesExplored++;
                        visited[i] = true;
                        lastNode->nextPtr = new Node();
                        lastNode->nextPtr->data = i+1;
                        lastNode = lastNode->nextPtr;
                        myQueue.push(i+1);
                    }
                }
            }
        }
    } else {
        
    }
}

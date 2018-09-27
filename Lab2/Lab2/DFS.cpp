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
#include <iterator>
DFS::DFS(){
    
}
void DFS::searchList(std::vector<std::vector<Node> > &adjList, int start, int finish, bool isRecur, std::vector<bool> visited, Node* lastNode){
    if(!isRecur){

        std::stack<Node> stack;
        std::vector<Node>::iterator it = adjList[start-1].begin();
        
        stack.push(*it);
        visited[start-1] = true;
        
        while(stack.size()){
            Node node = stack.top();
            stack.pop();
            
            for(it = adjList[node.data-1].begin()+1; it != adjList[node.data-1].end(); it++){
                if(it->data == finish){
                    nodesExplored++;
                    lastNode->nextPtr = new Node();
                    lastNode->nextPtr->data = it->data;
                    return;
                }
                std::vector<Node>::iterator nodeVisit = adjList[it->data-1].begin();
                if(!visited[nodeVisit->data-1]){
                    nodesExplored++;
                    lastNode->nextPtr = &*it;
                    visited[nodeVisit->data-1] = true;
                    stack.push(*it);
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
                nodesExplored++;
                visited[it->data-1] = true;
                lastNode->nextPtr = &*it;
                searchList(adjList, it->data, finish, true, visited, &*it);
            }
        }
    }
}
void DFS::searchMatrix(int** mat, int start, int finish, bool isRecur, std::vector<bool> visited, Node* lastNode) {
    if(!isRecur) {
        std::stack<int> stack;
        int val = start;
        
        stack.push(val);
        visited[start-1] = true;
        while(stack.size()){
            int node = stack.top();
            stack.pop();
            for(int i=start-1; i < finish; i++){
                if(mat[node-1][i] == 1 && node-1 != i) {
                    if(node == finish){
                        nodesExplored++;
                        lastNode->nextPtr = new Node();
                        lastNode->nextPtr->data = node;
                        lastNode = lastNode->nextPtr;
                        return;
                    }
                    if (!visited[i]) {
                        nodesExplored++;
                        visited[i] = true;
                        lastNode->nextPtr = new Node();
                        lastNode->nextPtr->data = i+1;
                        lastNode = lastNode->nextPtr;
                        stack.push(i+1);
                    }
                }
            }
        }
    } else {
        if(start == finish){
            nodesExplored++;
            return;
        }
        for(int i=start-1; i < finish; i++){//figure out what to make range
            if(mat[start-1][i] != 0 && !visited[i] && start-1 != i){
                nodesExplored++;
                lastNode->nextPtr = new Node();
                lastNode->nextPtr->data = i+1;
                lastNode = lastNode->nextPtr;
                visited[i] = true;
                //lastNode->nextPtr = &*it;
                searchMatrix(mat, i+1, finish, true, visited, lastNode);
            }
        }
    }
}

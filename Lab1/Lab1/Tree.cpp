//
//  Tree.cpp
//  Lab1
//
//  Created by Braden Wallace on 8/30/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#include "Tree.hpp"

/*struct Tree::Node * CreateNode(int id){
    struct Tree::Node* node = new Tree::Node();//finna make a destructor bc of new keyword
    node->key = id;
    node->left = 0;
    node->right = 0;
    return node;
}
struct Tree::Node * InsertNode(Tree::Node* node, int id){
    if(node == 0){
        return Tree::CreateNode(id);
    }
    if(id < node->key){
        node->left = Tree::InsertNode(node->left, id);
    }
    else if(id > node->key){
        node->right = Tree::InsertNode(node->right, id);
    }
    return node;
}
void Tree::CopySortedTree(Tree::Node* node, std::vector<int>& data, int& i){
    if(node!=0){
        Tree::CopySortedTree(node->left, data, i);
        data[i++] = node->key;
        Tree::CopySortedTree(node->right, data, i);
        
    }
}*/


//
//  Tree.hpp
//  Lab1
//
//  Created by Braden Wallace on 8/30/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

/*#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <vector>
class Tree{
public:
    struct Node{
        int key;
        struct Node *left, *right;
    };
    static struct Tree::Node * CreateNode(int id);
    static struct Tree::Node * InsertNode(Tree::Node*, int id);
    static void CopySortedTree(Tree::Node*, std::vector<int>&, int& i);
};
#endif /* Tree_hpp */


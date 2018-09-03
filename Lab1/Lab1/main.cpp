//
//  main.cpp
//  Lab1
//
//  Created by Braden Wallace on 8/28/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#include <iostream>
#include "Bubble.hpp"
#include "Insertion.hpp"
#include "Merge.hpp"
#include "Sort.hpp"
#include <vector>
#include <unordered_set>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
void swap(int* aPtr, int* bPtr){
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}
int main(int argc, const char * argv[]) {
    std::vector<int> stuff = {10,9,8,7,6,5,4,3,2,1};
    Sort file;
    file.load("Reverse10.txt");
    file.select(BUBBLE);
    file.excecute();
    //Bubble a;
    //a.sort(stuff);
    /*std::vector<int> stuff = {5,0,3,34,56,3,6,2,1};
    Merge a;
    a.sort(stuff);
    for(int x: stuff){
        std::cout << x << std::endl;
    }*/
    
    /*ofstream file;
    file.open("Random30percent100000.txt");
    if (!file) {
        cerr << "Unable to open file";
        exit(1);
    }
    srand(time(0));
    vector<int> nums= { };
    for(int i = 1; i <=100000;i++)
        nums.push_back(i);
    for(int i = 1; i <=nums.size()*.3;i++)
        nums[rand()%nums.size()] = rand()%nums.size();
    for(int i = 0; i <nums.size();i++)
        file << nums[i] << endl;
    file.close();
    cout << nums.size()*.3 << endl << endl;
    */
    /*ofstream file;
    file.open("Unique20percent10.txt");
    if (!file) {
        cerr << "Unable to open file";
        exit(1);
    }
    vector<int> nums= { };
    for(int i = 1; i<=10*.2;i++)
        nums.push_back(i);
    unordered_set<int> unique(nums.begin(),nums.end());
    for(int i = 10*.2+1; i<=10;i++){
        int randNum = rand()%10+1;
        while(unique.find(randNum)!=unique.end()){
            randNum = rand()%10+1;
        }
        nums.push_back(randNum);
    }
    for(int x: nums)
        file << x << endl;
    file.close();*/
    
    /*int middle = ((int)stuff.size()+ 1) / 2;
    std::vector<int> news(stuff.begin()+middle,stuff.end());
    for(int x: news){
        std::cout << x << std::endl;
    }*/
    return 0;
}

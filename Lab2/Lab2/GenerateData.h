//
//  GenerateData.hpp
//  Lab1
//
//  Created by Braden Wallace on 9/4/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef GenerateData_hpp
#define GenerateData_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include <ctime>
#include <unordered_set>
#include <algorithm>
#include <random>

class GenerateData{
public:
    void generate();
private:
    const std::vector<std::string> dataOrders = {"Reverse", "Random", "Random30percent", "Unique"};
    const std::vector<std::string> dataSizes = {"10","1000","10000","100000"};
};
void GenerateData::generate(){
    std::string dataOrder = dataOrders[0];
    for(int i = 0; i < dataSizes.size(); i++){
        std::vector<int> data;
        int size = std::stoi(dataSizes[i]);
        
        std::ofstream file;
        for(int j = size; j >= 1; j--)
            data.push_back(j);
        file.open("TestData/" + dataOrder + dataSizes[i] + ".txt");
        for(int x: data)
            file << x << std::endl;
        file.close();
    }
    
    dataOrder = dataOrders[1];
    for(int i = 0; i < dataSizes.size(); i++){
        srand((unsigned int)time(0));
        std::vector<int> data;
        int size = std::stoi(dataSizes[i]);
        
        std::ofstream file;
        for(int j = 1; j <= size; j++){
            data.push_back(rand() % size + 1);
        }
        
        file.open("TestData/" + dataOrder + dataSizes[i] + ".txt");
        for(int x: data)
            file << x << std::endl;
        file.close();
    }
    
    dataOrder = dataOrders[2];
    for(int i = 0; i < dataSizes.size(); i++){
        srand((unsigned int)time(0));
        std::vector<int> data;
        int size = std::stoi(dataSizes[i]);
        
        std::ofstream file;
        for(int i = 1; i <=size;i++)
            data.push_back(i);
        for(int i = 1; i <=data.size()*.3;i++)
            data[rand()%data.size()] = rand()%data.size();
        
        file.open("TestData/" + dataOrder + dataSizes[i] + ".txt");
        for(int x: data)
            file << x << std::endl;
        file.close();
    }
    
    dataOrder = dataOrders[3];
    auto rng = std::default_random_engine {};
    for(int i = 0; i < dataSizes.size(); i++){
        srand((unsigned int)time(0));
        std::vector<int> data;
        int size = std::stoi(dataSizes[i]);
        
        std::ofstream file;
        for(int i = 1; i<=size*.2;i++)
            data.push_back(i);
        std::unordered_set<int> unique(data.begin(),data.end());
        
        for(int i = size*.2+1; i<=size/2+size*.1;i++){
            int randNum = rand()%size+1;
            while(unique.find(randNum)!=unique.end()){
                randNum = rand()%size+1;
            }
            data.push_back(randNum);
            data.push_back(randNum);
        }
        file.open("TestData/" + dataOrder + dataSizes[i] + ".txt");
        
        std::shuffle(std::begin(data), std::end(data), rng);
        for(int x: data)
            file << x << std::endl;
        file.close();
    }
}

#endif /* GenerateData_hpp */

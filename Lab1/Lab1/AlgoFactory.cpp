//
//  AlgoFactory.cpp
//  Lab1
//
//  Created by Braden Wallace on 9/20/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#include "AlgoFactory.hpp"

#include "Sort.hpp"

Algorithm* AlgoFactory::Create(AlgoFactory::AlgorithmClass type){
    
    Algorithm* pAlgo;
    
    switch(type){
        case AlgoFactory::AlgorithmClass::SORT:
            pAlgo = new Sort();
            break;
        case AlgoFactory::AlgorithmClass::SEARCH:
            //pAlgo =
            break;
        case AlgoFactory::AlgorithmClass::HEURISTIC:
            //pAlgo =
            break;
    }
    return pAlgo;
}

//
//  AlgoFactory.hpp
//  Lab1
//
//  Created by Braden Wallace on 9/20/18.
//  Copyright © 2018 Braden Wallace. All rights reserved.
//

#ifndef AlgoFactory_hpp
#define AlgoFactory_hpp
class Algorithm;
class AlgoFactory {
public:
    enum AlgorithmClass {
        SORT = 0,
        SEARCH,
        HEURISTIC
    };
    static Algorithm* Create(AlgoFactory::AlgorithmClass type);
};
#include <stdio.h>

#endif /* AlgoFactory_hpp */

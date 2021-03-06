//
//  Demo.cpp
//  Iterable
//
//  Created by Adam Lev-Ari on 09/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include <iostream>

#include "cycle.hpp"
#include "accumulate.hpp"
#include "zip_longest.hpp"
#include "permutation.hpp"
#include "filter_false.hpp"
#include "output.h"

#include <vector>
using namespace itertools;
using namespace std;


struct lessThan
{
    template<typename T>
    bool operator()(T& i) const { return i < 3; }
};

int main(int argc, const char * argv[]) {
    
    vector<int> vecInit = {1,2,3,4};
    vector<string> vecString = {"Hello", "Bye", "Adam"};
    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};
    
    
    //Defined a final int for output
    cout << "####  Cycle:  ####" << endl;
    cout << "Finite<limit: 5 times> Cycle of numbers vector: " << endl;
    for (auto i: cycle(vecInit,5))
        cout << i;    // 1234 1234 1234 ...
    cout << endl << endl;
    
    cout << "####  Accumulate:  ####";
    cout << endl << "Accumulate of vector<string>: " << endl;
    for (auto i: accumulate(vecString) )
        cout << i << " ";
    cout << endl << endl;
    
    cout << "####  Accumulate & Cycle:  ####";
    cout << endl << "Cycle of Accumulate of string vector: " << endl;
    for (auto i: cycle(accumulate(vecString),2) )
        cout << i << " ";
    cout << endl << endl;
    
    cout << "####  Zip_Longest:  ####";
    cout << endl << "zip longest of vector<float> & vector<int>: " << endl;
    for (auto i: zip_longest(vecFloat, vecInit) )
        cout << i << " ";
    cout << endl << endl;
    
    cout << "####  Zip_Longest & Cycle:  ####";
    cout << endl << "zip longest of Cycle<vector:{1,2,3,4}> & Cycle<vector:{-1, 0.3, 5.2, -8.3}>: " << endl;
    for (auto i: zip_longest(cycle(vecInit,2), cycle(vecFloat,2)) )
        cout << i << " ";
    cout << endl << endl;
    
    
    cout << "####  Permutation:  ####";
    cout << endl << "Permutation of vector:{1,2,3,4}" << endl;
    for (auto i: permutation(vecInit) )
        cout << i;
    cout << endl << endl;
    
    
    cout << "####  Filter False:  ####";
    cout << endl << "Filter all numbers less than 3 in vector{1,2,3,4}: " << endl;
    for (auto i: filter_false(vecInit, lessThan()) )
    cout << i << " ";
    cout << endl << endl;

    
    cout << endl;
    return 0;
}




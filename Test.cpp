//
//  badkan.cpp
//  CutAndChoose
//
//  Created by Adam Lev-Ari on 21/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include "doctest.h"
#include <iostream>
#include <vector>

Using namespace itertools;
Using namespace std;

TEST_CASE("Test case 1") {
   vector<int> vecInit = {1,2,3,4};
    vector<string> vecString = {"Hello", "Bye", "Nathan", "Adam"};
    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};
    vector<string> resualt = {"Hello", "HelloBye", "HelloByeNathan", "HelloByeNathanAdam"};
    int index = 0;

    for (auto i: Accumulate(vecString)){
        CHECK(i == resualt.at(index));
        index++;
    }

    
  // CHECK((solve((2*x^2) - 4*x + 3 == 9)) == 3);
    
}

TEST_CASE("Test case 2") {
    int index = 0;

    for (auto i: Accumulate(vecString)){
        CHECK(i == resualt.at(index));
        index++;
    }
   //CHECK((solve((2*y^2) - 4*y + 3 == 9)) == 3);
    
}


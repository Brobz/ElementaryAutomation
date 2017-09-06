//
//  Rule.cpp
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/4/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#include "Rule.h"

const array<string, 8> Rule::PATTERNS = {"111", "110", "101", "100", "011", "010", "001", "000"};

Rule::Rule(int ruleID){
    decimalID = ruleID;
    binaryID = getBinary(ruleID);
}

Rule::Rule(string ruleID){
    binaryID = ruleID;
    decimalID = getDecimal(ruleID);
}

int Rule::rule(string states){
    for(int i = 0; i < PATTERNS.size(); i++){
        if(states == PATTERNS[i]){
            return binaryID[i] - '0';
        }
    }
}


int Rule::rule(array<int, 3> states){
    
}


string Rule::getBinary(int n){
    string b = "00000000";
    while(n > 1){
        int h = floor(log2f((float) n));
        b[7 - h] = '1';
        n -= pow(2,  h);
    }
    
    if(n) b[7] = '1';
    
    return b;
}

int Rule::getDecimal(string b){
    int n = 0;
    for(int i = 0; i < b.length(); i++){
        n += (b[7 - i] - '0') * (pow(2, i));
    }
    
    return n;
}

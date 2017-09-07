//
//  Rule.h
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/4/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#ifndef Rule_h
#define Rule_h
#include <Cell.h>
#include <string>
#include <math.h>


class Rule{

    static const array<string, 8> PATTERNS;
    
public:
    Rule(int ruleID);
    Rule(string ruleID);
    int rule(string states);
    int rule(array<int, 3> states);
private:
    string binaryID;
    int decimalID;
    string getBinary(int n);
    int getDecimal(string b);
};


#endif /* Rule_h */

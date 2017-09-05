//
//  Cell.h
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/4/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#ifndef Cell_h
#define Cell_h
#include <iostream>
#include <stdlib.h>
#include <array>
using namespace std;

class Cell
{

public:
    Cell(int state, array<int, 2> position);
    Cell(int state);
    Cell();
    array<int, 2> getPosition();
    int getState();
    void setState(int newState);
    void setPosition(array<int, 2> newPosition);
private:
    array<int, 2> position;
    int state;

};

#endif /* Cell_h */

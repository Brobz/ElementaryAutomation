//
//  Cell.cpp
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/4/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#include "Cell.h"


Cell::Cell(){
}

Cell::Cell(int state){
    setState(state);
    setPosition(array<int, 2>{0, 0});
}

Cell::Cell(int state, array<int, 2> position){
    setState(state);
    setPosition(position);
}

int Cell::getState(){
    return state;
}

array<int, 2> Cell::getPosition(){
    return position;
}

void Cell::setState(int newState){
    state = newState;
}

void Cell::setPosition(array<int, 2> newPosition){
    position = newPosition;
}

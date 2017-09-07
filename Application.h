//
//  Application.h
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/4/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#ifndef Application_h
#define Application_h

// Libs
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <array>


// Helper Tool
#include "ResourcePath.hpp"

// My classes
#include "Cell.h"
#include "Rule.h"
#include "Switch.h"

class Application
{
    
public:
    Application();
    
    void run();

    
private:
    int current_y = 0;
    template <typename F>
    void forEachCell(F f){
        for(unsigned x = 0; x < WIDTH; x++){
            f(x);
        }
    }
    template <typename F>
    void forAllCells(F f){
        for(unsigned y = 0; y < HEIGHT; y++){
            for(unsigned x = 0; x < WIDTH; x++){
                f(x, y);
            }
        }
    }
    
    void update();
    void pollEvents();
    void tickCells();
    void overflow();
    void rollUp();
    const float WIDTH, HEIGHT;
    Rule rule;
    RenderWindow window;
    vector<Vertex> pixels;
    vector<Cell::Cell> cells;
    void initializeCells(string pattern);
    int getIndex(int x);
    int getIndex(int x, int y);
    Font app_font;
    int ticksPerFrame = 2;
    
    Button button_test;
    Switch switch_test;
    bool left_mouse_button_down;
};

#endif /* Application_h */

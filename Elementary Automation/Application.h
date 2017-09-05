//
//  Application.h
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/4/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#ifndef Application_h
#define Application_h


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Helper Tool
#include "ResourcePath.hpp"

using namespace sf;
using namespace std;

class Application
{
    
public:
    Application();
    
    void run();
    
    void pollEvents();
    
private:
    template <typename F>
    void forEachCell(F f){
        for(unsigned y = 0; y < HEIGHT; y++){
            for(unsigned x = 0; x < WIDTH; x++){
                f(x, y);
            }
        }
    }
    void update();
    const float WIDTH, HEIGHT;
    
    RenderWindow window;
    vector<Vertex> pixels;
    
    int getIndex(int x, int y);
};

#endif /* Application_h */

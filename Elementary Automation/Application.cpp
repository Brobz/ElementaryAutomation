//
//  Application.cpp
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/4/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#include "Application.h"

Application::Application()
:
    WIDTH (1200),
    HEIGHT (600),
    window ({(unsigned)WIDTH, (unsigned)HEIGHT}, "Elementary Automation"),
    rule(110),
    cells(WIDTH * HEIGHT),
    pixels(WIDTH * HEIGHT)
{
    
    initializeCells("1");
    
    /*/
     // Set the Icon
     Image icon;
     if (!icon.loadFromFile(resourcePath() + "icon.png")) {
     return EXIT_FAILURE;
     }
     window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
     
     // Load a sprite to display
     Texture texture;
     if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
     return EXIT_FAILURE;
     }
     Sprite sprite(texture);
     
     // Create a graphical text to display
     Font font;
     if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
     return EXIT_FAILURE;
     }
     Text text("Hello SFML", font, 50);
     text.setFillColor(Color::Black);
     /*/
    
    
};


void Application::run()
{
    while(window.isOpen()){
        
        // Clear screen
        window.clear();
        
        /*/
         // Draw the sprite
         window.draw(sprite);
         
         // Draw the string
         window.draw(text);
         /*/
        
        tickCells();
        
        window.draw(pixels.data(), pixels.size(), Points);
        
        // Update the window
        window.display();
        
        //Process Events
        pollEvents();
    }

};

int Application::getIndex(int x)
{
    return current_y * WIDTH + x;
};

int Application::getIndex(int x, int y)
{
    return y * WIDTH + x;
};

void Application::tickCells(){
    forEachCell([&](int x){
        string states;
        
        int index = getIndex(x);
        int next_index;
        next_index = getIndex(x, current_y + 1);
        
        Cell::Cell &cell = cells[index];
        Cell::Cell &next_cell = cells[next_index];
        
        Vertex &pixel = pixels[next_index];
        
        
        if(!x){
            
            states = to_string(cell.getState()) + to_string(cells[index + 1].getState()) + to_string(cells[index + 2].getState());
            
        }else if(x == cells.size() - 1){
            
            states = to_string(cells[index - 2].getState()) + to_string(cells[index - 1].getState()) + to_string(cell.getState());
            
        }else{
            
            states = to_string(cells[index - 1].getState()) + to_string(cell.getState()) + to_string(cells[index + 1].getState());
            
        }
        next_cell.setState(rule.rule(states));
        if(next_cell.getState()){
            pixel.color = {0, 0, 0};
        }else{
            pixel.color = {255, 255, 255};
        }
        
    });
};

void Application::initializeCells(string pattern){
    int counter = 0;
    for(int i = 0; i < cells.size(); i++){
        cells[i].setState(pattern[counter] - '0');
        counter++;
        if(counter > pattern.length() - 1) counter = 0;
    }
    
    forAllCells([&](int x, int y){
        int index = getIndex(x, y);
        Cell::Cell &cell = cells[index];
        Vertex &pixel = pixels[index];
        
        cell.setPosition({x, y});
        pixel.position = {(float) x, (float) y};
        
    });
}

void Application::pollEvents()
{
    // Process events
    Event event;
    while (window.pollEvent(event))
    {
        // Close window: exit
        if (event.type == Event::Closed) {
            window.close();
        }
        
        
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
            //Space has been (or is) pressed;
            //tickCells();
        }
        
        
        
        
    }
};

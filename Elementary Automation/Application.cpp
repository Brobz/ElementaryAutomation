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
    pixels (WIDTH * HEIGHT)
{
    
    forEachCell([&](int x, int y){
        Vertex &pixel = pixels[getIndex(x,y)];
        pixel.position = {(float) x, (float) y};
        pixel.color = {(uint8_t)x, (uint8_t)y, 0};
    });
    
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
        
        window.draw(pixels.data(), pixels.size(), Points);
        
        // Update the window
        window.display();
        
        //Process Events
        pollEvents();
    }

};

int Application::getIndex(int x, int y)
{
    return y * WIDTH + x;
};

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
        
        /*/
         // Escape pressed: exit
         if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
         window.close();
         }
         /*/
        
    }
};

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
    WIDTH (800),
    HEIGHT (500),
    window ({(unsigned)WIDTH, (unsigned)HEIGHT}, "Elementary Automation"),
    rule(30), // 110, 109
    cells(WIDTH * HEIGHT),
    pixels(WIDTH * HEIGHT),
    gui()
{
    gui.initGUI();
    initializeCells("110110110");

    buttonFunctions.push_back(&Application::tickCellsBF);

    switchFunctions.push_back(&Application::changeWrappingModeSF);
    switchFunctions.push_back(&Application::tickCellsSF);

    /*/
    // Set the Icon
    Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
    return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    /*/

};


void Application::run()
{
    while(window.isOpen()){

        // Clear screen
        window.clear();

        window.draw(pixels.data(), pixels.size(), Points);

        for (int i = 0; i < gui.switches.size(); i++) {
            gui.switches[i].update(&window, (Vector2f) Mouse::getPosition(window));
            gui.switches[i].doIfSwitched([&](){
                __invoke(switchFunctions[i], this);
            });
        }

        for (int i = 0; i < gui.buttons.size(); i++) {
            gui.buttons[i].update(&window, (Vector2f) Mouse::getPosition(window));
            gui.buttons[i].doIfClicked([&](){
                __invoke(buttonFunctions[i], this);
            });
        }

        // Update the window
        window.display();

        //Process Events
        pollEvents();

        // Reset Wrapping Mode
        wrappingMode = 0;
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

        Cell &cell = cells[index];
        Cell &next_cell = cells[next_index];

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

    if(!wrappingMode) overflow();
    else rollUp();
};

void Application::rollUp(){
    current_y++;
    if (current_y * (WIDTH + 2) > cells.size()){
        forAllCells([&](int x, int y){
            cells[y * WIDTH + x].setState( cells[(y + 1) * WIDTH + x].getState() );
            pixels[y * WIDTH + x].color = pixels[(y + 1) * WIDTH + x].color;
        });
        current_y -= 1;
    }
}

void Application::overflow(){
    current_y++;
    if (current_y * (WIDTH + 2) > cells.size()){
        for(int i = 0; i < WIDTH; i++){
            cells[i] = cells[current_y * WIDTH + i];
            pixels[i] = pixels[current_y * WIDTH + i];
        }
        current_y = 0;
    }
}

void Application::initializeCells(string pattern){
    int counter = 0;
    for(int i = 0; i < cells.size(); i++){
        cells[i].setState(pattern[counter] - '0');
        counter++;
        if(counter > pattern.length() - 1) counter = 0;
    }

    forAllCells([&](int x, int y){
        int index = getIndex(x, y);
        Cell &cell = cells[index];
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


        if ( event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            left_mouse_button_down = false;
        }


        if ( event.type == event.MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            left_mouse_button_down = true;
            for (int i = 0; i < gui.switches.size(); i++) {
                gui.switches[i].checkIfClicked(left_mouse_button_down);
            }
        }




    }
};

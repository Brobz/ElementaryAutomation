//
//  GUI.cpp
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/9/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#include "GUI.h"


void GUI::initGUI(){
    if(!app_font.loadFromFile("Welbut.ttf")){
        return;
    }

    Button tick_button = Button(Color::Black, Color::Cyan, UIText(app_font, "Tick Cells", Color::White, {10, 10}, 15), {10, 10}, {82, 20});

    Switch switch_tick_button = Switch(Color::Red, Color::Green, Color::Cyan, UIText(app_font, "Switch On", Color::White, {10, 50}, 15), UIText(app_font, "Switch Off", Color::White, {10, 50}, 14), {10, 50}, {88, 20});

    Switch switch_wrapping = Switch(Color::Red, Color::Green, Color::Cyan, UIText(app_font, "Overflow", Color::White, {10, 80}, 15), UIText(app_font, "Roll Up", Color::White, {10, 80}, 14), {10, 80}, {88, 20});

    buttons.push_back(tick_button);


    switches.push_back(switch_wrapping);
    switches.push_back(switch_tick_button);

    for(int i = 0; i < buttons.size(); i++){
        (*(&buttons[i])->getText()).setFont(app_font);
        (&buttons[i])->setState(true);
    }

    for(int i = 0; i < switches.size(); i++){
        (*(&switches[i])->getText()).setFont(app_font);
        (*(&switches[i])->getClickedText()).setFont(app_font);
        (&switches[i])->setState(true);
    }

}

//
//  GUI.h
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/9/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#ifndef GUI_h
#define GUI_h
#include "Switch.h"
#include <vector>

class GUI {
public:
    Font app_font;
    vector<Button> buttons;
    vector<Switch> switches;

    void initGUI();
};

#endif /* GUI_h */

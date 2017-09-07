//
//  UIText.h
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/6/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#ifndef UIText_h
#define UIText_h
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;


class UIText{

public:
    UIText();
    UIText(Font font, string text, Color color, Vector2f position, int size);
    
    void setFont(Font new_font);
    Font getFont();
    void setText(string new_text);
    string getText();
    void setColor(Color new_color);
    Color getColor();
    void setHoverColor(Color new_hover_color);
    Color getHoverColor();
    void setPosition(Vector2f new_position);
    Vector2f getPosition();
    void setSize(int new_size);
    int getSize();
    void setState(bool new_state);
    bool getState();
    
    void render(RenderWindow* window, bool hovered = false);
private:
    Font font;
    string text;
    Color color;
    Color hover_color;
    Vector2f position;
    int size;
    bool state;
    Text label;
};

#endif /* UIText_h */

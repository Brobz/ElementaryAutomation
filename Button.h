//
//  Button.h
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/5/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#ifndef Button_h
#define Button_h

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
using namespace sf;
using namespace std;

class Button {
public:
    Button(Texture* rest_texture, Texture* hover_texture, string text, Vector2f position);
    Button(Color rest_color, Color hover_color, string text, Vector2f position, Vector2f size, Font font);
    bool isHovered (Vector2f mouse_pos);
    template <typename F>
    void doIfClicked (F f){
        if(hovered && Mouse::isButtonPressed(Mouse::Left)) f();
    }
    void setState(bool);
    bool getState();
    void setText(string);
    Sprite* getRestSprite();
    Sprite* getHoverSprite();
    Font* getFont();
    void setFont(Font* new_font);
    void setRestSprite(Sprite* new_sprite);
    void setHoverSprite(Sprite* new_sprite);
    Text* getText();
    void update(RenderWindow* window, Vector2f mouse_pos);
    void render(RenderWindow* window);
private:
    Font font;
    RectangleShape rect;
    Vector2f position;
    Sprite rest_sprite;
    Sprite hover_sprite;
    Color rest_color;
    Color hover_color;
    Text label;
    bool state;
    bool hovered;
    void setupFont(string text);
};

#endif /* Button_h */
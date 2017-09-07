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
#include "UIText.h"
#include <iostream>
using namespace sf;
using namespace std;

class Button {
public:
    Button(Texture* rest_texture, Texture* hover_texture, Vector2f position);
    Button(Color rest_color, Color hover_color, UIText text, Vector2f position, Vector2f size);
    bool isHovered (Vector2f mouse_pos);
    bool isHovered ();
    template <typename F>
    void doIfClicked (F f){
        if(hovered && Mouse::isButtonPressed(Mouse::Left)) f();
    }
    void setState(bool);
    bool getState();
    void setText(UIText* new_text);
    Sprite* getRestSprite();
    Sprite* getHoverSprite();
    void setRestSprite(Sprite* new_sprite);
    void setHoverSprite(Sprite* new_sprite);
    UIText* getText();
    void update(RenderWindow* window, Vector2f mouse_pos);
    virtual void render(RenderWindow* window);
    RectangleShape* getRect();
    void setRect(RectangleShape* new_rect);
    void setRestColor(Color new_rest_color);
    Color getRestColor();
    void setHoverColor(Color new_hover_color);
    Color getHoverColor();
private:
    UIText text;
    RectangleShape rect;
    Vector2f position;
    Sprite rest_sprite;
    Sprite hover_sprite;
    Color rest_color;
    Color hover_color;
    bool state;
    bool hovered;
    void setupFont(string text);
};

#endif /* Button_h */

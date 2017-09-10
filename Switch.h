//
//  Switch.h
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/7/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#ifndef Switch_h
#define Switch_h
#include "Button.h"

class Switch : public Button{

public:
    Switch(Texture* rest_texture, Texture* clickedTexture, Texture* hover_texture, Vector2f position);
    Switch(Color rest_color, Color hover_color, Color color, UIText text, UIText clicked_text, Vector2f position, Vector2f size);
    template <typename F>
    void doIfSwitched (F f){
        if(isClicked) f();
    }
    void checkIfClicked(bool mouse_down);
    void render(RenderWindow* window);
    Sprite* getClickedSprite();
    void setClickedSprite(Texture* new_clicked_texture);
    Color getColor();
    void setColor(Color new_color);
    UIText* getClickedText();
private:
    bool isClicked = false;
    bool mouse_button_down;
    Color color;
    Sprite clickedSprite;
    UIText clicked_text;
};

#endif /* Switch_h */

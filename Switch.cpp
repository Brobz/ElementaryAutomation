//
//  Switch.cpp
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/7/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#include "Switch.h"


Switch::Switch(Texture* rest_texture, Texture* clickedTexture, Texture* hover_texture, Vector2f position) : Button::Button(rest_texture, hover_texture, position) {
    (*this).clickedSprite.setTexture(*clickedTexture);
}


Switch::Switch(Color rest_color, Color color, Color hover_color, UIText text, UIText clicked_text, Vector2f position, Vector2f size) : Button::Button(rest_color, hover_color, text, position, size){
    (*this).color = color;
    (*this).clicked_text = clicked_text;
}

void Switch::checkIfClicked(bool mouse_down){
    if(isHovered()){
        if(mouse_down){
            isClicked = !isClicked;
        }
    }
}

void Switch::render(sf::RenderWindow *window){
    if(getState()){
        if(isHovered()){
            if((*getHoverSprite()).getTexture() != NULL){
                (*window).draw((*getHoverSprite()));
            }else{
                (*getRect()).setFillColor(getHoverColor());
                (*window).draw((*getRect()));
                if(isClicked) clicked_text.render(window, true);
                else (*getText()).render(window, true);
            }

        }else if(isClicked){
            if((*getClickedSprite()).getTexture() != NULL){
                (*window).draw((*getClickedSprite()));
            }else{
                (*getRect()).setFillColor(getColor());
                (*window).draw((*getRect()));
                clicked_text.render(window, true);
            }
        }else{
            if((*getRestSprite()).getTexture() != NULL){
                (*window).draw((*getRestSprite()));
            }else{
                (*getRect()).setFillColor(getRestColor());
                (*window).draw((*getRect()));
                (*getText()).render(window);
            }
        }
    }
}

Sprite* Switch::getClickedSprite(){
    return &clickedSprite;
}
void Switch::setClickedSprite(Texture* new_clicked_texture){
    clickedSprite.setTexture(*new_clicked_texture);
}

UIText* Switch::getClickedText(){
    return &clicked_text;
}

Color Switch::getColor(){
    return color;
}
void Switch::setColor(Color new_color){
    color = new_color;
}

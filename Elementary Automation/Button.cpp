//
//  Button.cpp
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/5/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#include "Button.h"

Button::Button(Texture* rest_texture, Texture* hover_texture, string text, Vector2f position) {
    rest_sprite.setTexture(*rest_texture);
    hover_sprite.setTexture(*hover_texture);
    rest_sprite.setPosition(position);
    hover_sprite.setPosition(position);
    label.setString(text);
    label.setPosition(position.x + 3, position.y + 3);
    label.setCharacterSize(14);
    rect.setSize({(float)(rest_sprite.getTextureRect().width), (float)(rest_sprite.getTextureRect().height)});
    rect.setPosition(position);
}

Button::Button(Color rest_color, Color hover_color, string text, Vector2f position, Vector2f size) {
    (*this).rest_color = rest_color;
    (*this).hover_color = hover_color;
    rect.setSize(size);
    rect.setOutlineColor(Color::Black);
    rect.setOutlineThickness(2);
    rect.setPosition(position);
    label.setString(text);
    label.setPosition(position.x + 3, position.y + 3);
    label.setCharacterSize(14);
}

bool Button::isHovered(Vector2f mouse_pos) {
    if(mouse_pos.x >= rect.getPosition().x && mouse_pos.x <= rect.getPosition().x + rect.getSize().x && mouse_pos.y >= rect.getPosition().y && mouse_pos.y <= rect.getPosition().y + rect.getSize().y){
        return true;
    }
    return false;
}
void Button::update(RenderWindow *window, Vector2f mouse_pos){
    hovered = isHovered(mouse_pos);
    render(window);
}

void Button::render(RenderWindow *window){
    if(state){
        if(hovered){
            if(hover_sprite.getTexture() != NULL){
                (*window).draw(hover_sprite);
            }else{
                rect.setFillColor(hover_color);
                (*window).draw(rect);
            }
        }else{
            if(rest_sprite.getTexture() != NULL){
                (*window).draw(rest_sprite);
            }else{
                rect.setFillColor(rest_color);
                (*window).draw(rect);
            }
        }
    }
}

bool Button::getState() {
    return state;
}

void Button::setState(bool new_state) {
    state = new_state;
}

void Button::setText(string text) {
    label.setString(text);
}

Sprite* Button::getRestSprite() {
    return &rest_sprite;
}

Sprite* Button::getHoverSprite() {
    return &hover_sprite;
}

void Button::setRestSprite(Sprite* new_sprite) {
    rest_sprite = *new_sprite;
}

void Button::setHoverSprite(Sprite *new_sprite) {
    hover_sprite = *new_sprite;
}

Text* Button::getText() {
    return &label;
}


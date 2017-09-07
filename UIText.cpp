//
//  UIText.cpp
//  Elementary Automation
//
//  Created by Guilherme Borba on 9/6/17.
//  Copyright © 2017 Guilherme Borba. All rights reserved.
//

#include "UIText.h"

UIText::UIText(){

}
UIText::UIText(Font font, string text, Color color, Vector2f position, int size){
    
    setFont(font);
    setText(text);
    setColor(color);
    setPosition({position.x, position.y});
    setSize(size);
}

void UIText::setFont(Font new_font){
    font = new_font;
    label.setFont(font);
}
Font UIText::getFont(){
    return font;
}
void UIText::setText(string new_text){
    text = new_text;
    label.setString(text);
}
string UIText::getText(){
    return text;
}
void UIText::setColor(Color new_color){
    color = new_color;
    label.setFillColor(color);
}
Color UIText::getColor(){
    return color;
}
void UIText::setHoverColor(Color new_hover_color){
    hover_color = new_hover_color;
}
Color UIText::getHoverColor(){
    return hover_color;
}
void UIText::setPosition(Vector2f new_position){
    position = new_position;
    label.setPosition(position.x, position.y);
}
Vector2f UIText::getPosition(){
    return position;
}
void UIText::setSize(int new_size){
    size = new_size;
    label.setCharacterSize(size);
}
int UIText::getSize(){
    return size;
}
void UIText::setState(bool new_state){
    state = new_state;
}
bool UIText::getState(){
    return state;
}

void UIText::render(RenderWindow* window, bool hovered){
    if(hovered) label.setFillColor(hover_color);
    (*window).draw(label);
    label.setFillColor(color);
}


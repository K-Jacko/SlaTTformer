//
// Created by Wake on 2/19/2023.
//
#include "../include/Character.h"
#include "../include/Entity.h"

Character::Character() {}

void Character::SetX(int x){    posX = x;}

void Character::SetY(int y){    posY = y;}

int Character::getX() { return posX;}

int Character::getY() { return posY;}

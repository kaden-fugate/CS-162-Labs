#include <iostream>
#include "shapeheader.h"

Shape::Shape(std::string color, std::string name) : name(name){

    this->color = color;

}

//Shape::~Shape(){}

std::string Shape::get_color(){

    return this->color;

}

std::string Shape::get_name(){

    return this->name;

}

float area(){}
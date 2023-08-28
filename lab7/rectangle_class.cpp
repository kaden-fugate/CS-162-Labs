#include <iostream>
#include "shapeheader.h"
#include "rectangleheader.h"

Rectangle::Rectangle(float width, float height, std::string name, std::string color) : Shape(color, name){

    this->width = width;
    this->height = height;

}

//Rectangle::~Rectangle(){}

float Rectangle::area(){

    float area;

    area = width * height;

    return area;

}



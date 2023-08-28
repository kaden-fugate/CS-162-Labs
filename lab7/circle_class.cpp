#include <iostream>
#include "shapeheader.h"
#include "circleheader.h"

Circle::Circle(float radius, std::string color) : Shape(color, "Circle"){

    this->radius = radius;

}

//Circle::~Circle(){}

float Circle::area(){

    float area = 3.1415 * (this->radius * this->radius);

    return area;

}
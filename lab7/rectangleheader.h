#ifndef RECTANGLEHEADER_H
#define RECTANGLEHEADER_H

#include <iostream>
#include "shapeheader.h"

class Rectangle : public Shape {

    private:

        float width;
        float height;
    
    public:

        Rectangle(float, float, std::string, std::string);
        //~Rectangle();
        float area();

};

#endif
#ifndef SHAPEHEADER_H
#define SHAPEHEADER_H

#include <iostream>

class Shape{

    protected:
    
        const std::string name;
        std::string color;
    
    public:

        Shape(std::string, std::string);
        //virtual ~Shape();
        std::string get_color();
        std::string get_name();
        virtual float area() = 0;
        

};

#endif
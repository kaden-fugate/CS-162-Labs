#include <iostream>
#include <vector>
#include "squareheader.h"
#include "rectangleheader.h"
#include "circleheader.h"
#include "shapeheader.h"

void print_shape_info(Shape &shape);
void populate_vec(std::vector<Shape*> &shape_arr);

int main(){

    std::vector< Shape* > shape_arr;

    populate_vec(shape_arr);

    for(int i = 0; i < shape_arr.size(); i++){

        print_shape_info(*shape_arr.at(i));

        delete shape_arr.at(i);

    }


    return 0;

}

void print_shape_info(Shape &shape){

    std::cout << "\nName: " << shape.get_name() << "\n";
    std::cout << "Color: " << shape.get_color() << "\n";
    std::cout << "Area: " << shape.area() << "\n\n";

}

void populate_vec(std::vector<Shape*> &shape_arr){

    // didnt want to make a function to take these in as cin so i did it manually instead

    shape_arr.push_back(new Rectangle(10, 5, "Rectangle", "Yellow"));
    shape_arr.push_back(new Circle(5, "Blue"));
    shape_arr.push_back(new Square(5, "Green"));
    shape_arr.push_back(new Circle(10, "Orange"));
    shape_arr.push_back(new Square(9, "Red"));
    shape_arr.push_back(new Rectangle(2.1718, 3.1415, "Rectangle", "Black"));
    shape_arr.push_back(new Circle(0.5, "White"));
    shape_arr.push_back(new Square(12, "Purple"));
    shape_arr.push_back(new Circle(2.1718, "Periwinkle"));
    shape_arr.push_back(new Square(1, "Pink"));

}
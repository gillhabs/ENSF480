/*
* File Name: Rectangle.h
* Assignment: Lab 2 Exercise B
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 2, 2023
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "Shape.h"
#include "Square.h"
#include "Point.h"

using namespace std;


class Rectangle: public Square{
private:
    double side_b;


public:
    Rectangle(double rect_x, double rect_y, double a, double b, char const* name);
    
    double Rec_perimeter();
    double Rec_area();

    //Getter
    double Rec_getSideB();
    void set_side_a(double a);
    void set_side_b(double b);
    double get_rectX();
    double get_rectY();


    void display();
    
};

#endif


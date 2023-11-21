/*
* File Name: CurveCut.h
* Assignment: Lab 3 Exercise A
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 2, 2023
*/

#ifndef CURVECUT_H
#define CURVECUT_H
#include <iostream>
#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
using namespace std;


class CurveCut : public Circle, public Rectangle{
    public:
        CurveCut(double C_x, double C_y, double length, double width, double C_radius, char const* name);
        double get_radius();
        double getSideA();
        double getSideB();
        double area();
		double perimeter();
		void display();
};
#endif

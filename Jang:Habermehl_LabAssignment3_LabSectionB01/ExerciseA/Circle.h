/*
* File Name: Circle.h
* Assignment: Lab 3 Exercise A
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 2, 2023
*/

#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "Shape.h"
#include "Point.h"
#include <math.h>
#include <cmath>

using namespace std;


class Circle: virtual public Shape{
private:
    double radius;

public:
    Circle(double circle_x, double circle_y, double r, char const* name); 
    double perimeter();
    double area();
    double get_radius();
    void set_radius(double r);
    void display();
    
};

#endif


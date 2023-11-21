/*
* File Name: Point.cpp
* Assignment: Lab 1 Exercise D
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Sept 18, 2023
*/

#include "Point.h"


Point::Point(){} // Constructor

Point::Point(double a, double b) : x(a), y(b) {}

double Point::get_x() const { // Getter
    return x;
}

double Point::get_y() const { // Getter
    return y;
}

void Point::set_x(double a) { // Setter
    x = a;
}

void Point::set_y(double a) { // Setter
    y = a;
}
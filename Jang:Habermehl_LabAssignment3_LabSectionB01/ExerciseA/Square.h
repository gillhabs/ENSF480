/*
* File Name: Square.h
* Assignment: Lab 3 Exercise A
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 7, 2023
*/

#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <cmath>
#include <string.h>
#include "Shape.h"
#include "Point.h"

using namespace std;


class Square: virtual public Shape{
protected:
    double side_a;

public:
    Square(double x, double y, double a, char const* name);
    double perimeter();
    double area();
    //Getter
    double getSideA();
    void setSideA(double a);
    double get_squareX();
    double get_squareY();


    void display();

};

#endif


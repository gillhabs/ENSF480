/*
* File Name: Shape.h
* Assignment: Lab 3 Exercise A
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 7, 2023
*/

#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <cmath>
#include <string.h>
#include "Point.h"
using namespace std;


class Shape{
    protected:
        Point origin; // Used in getOrigin
        char* shapeName; //used in getName

    public:
        Shape(const Point& p, const char* name); //constructor that initializes its data members
        ~Shape();   //destructor
        Shape(const Shape& other);
        //Getter
        virtual char* getName() const;
        Shape& operator =(Shape& rhs);
        Point& getOrigin();
        double get_x()const;
        double get_y()const;

        double distance (Shape& other);
        static double distance (Shape& the_shape, Shape& other);
        void move (double dx, double dy);
        
        virtual void display();
        virtual double area()=0;
		double virtual perimeter()=0;


};

#endif
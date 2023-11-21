/*
* File Name: Circle.cpp
* Assignment: Lab 3 Exercise A
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 7, 2023
*/

#include "Circle.h"

Circle::Circle(double circle_x, double circle_y, double r, char const* name):Shape(Point(circle_x, circle_y), name){
    this->radius = r;
}


double Circle::perimeter(){
    return (2*M_PI*radius);
}
double Circle::area(){
    return((radius*radius)*M_PI);
}

double Circle::get_radius(){
    return radius;
}
void Circle::set_radius(double r){
    radius = r;
}

void Circle::display(){
    cout << "\nCircle Name: " << this->getName() 
    << "\nX-Coordinate: "<< this->origin.get_x() 
    << "\nY-Coordinate: " << this->origin.get_y()
    << "\nRadius: "<<radius
    <<"\nArea: "<< area() 
    << "\nPerimeter: " << perimeter()
            <<std::endl;
}
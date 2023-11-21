/*
* File Name: Square.cpp
* Assignment: Lab 3 Exercise A
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 7, 2023
*/

#include "Square.h"

Square::Square(double point_x, double point_y, double a, const char* name) : 
Shape(Point(point_x, point_y), name){
    this->side_a = a;
}
double Square::area(){
	return side_a * side_a;
}

double Square::perimeter(){
    return (side_a *2) + (side_a *2);
}

//Getter
double Square::getSideA(){
    return side_a;
}
//Setter
void Square::setSideA(double a){
	side_a = a;
}

double Square::get_squareX(){
    return this->origin.get_x();
}

double Square::get_squareY(){
    return this->origin.get_y();
}

void Square::display()
{
    cout << "Square Name: " << this->getName() 
    << "\nX-Coordinate: "<< get_squareX() 
    << "\nY-Coordinate: " << get_squareY()
    << "\nSide a: "<<side_a
    <<"\nArea: "<< area() 
    << "\nPerimeter: " << perimeter()
            <<std::endl;
}
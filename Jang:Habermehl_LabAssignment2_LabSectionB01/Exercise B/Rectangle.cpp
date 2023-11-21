/*
* File Name: Rectangle.cpp
* Assignment: Lab 2 Exercise B
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 2, 2023
*/

#include "Rectangle.h"

Rectangle::Rectangle(double rect_x, double rect_y, double a, double b, char const* name): Square(rect_x, rect_y, a, name) {
    this->side_b = b;
}
double Rectangle::Rec_area(){
	return side_a * side_b;
}

double Rectangle::Rec_perimeter(){
    return (side_a *2) + (side_b *2);
}

//Getter
double Rectangle::Rec_getSideB(){
    return side_b;
}

//Setter
void Rectangle::set_side_a(double a){
    side_a = a;
}

void Rectangle::set_side_b(double b){
	side_b = b;
}

double Rectangle::get_rectX(){
    return this->origin.get_x();
}

double Rectangle::get_rectY(){
    return this->origin.get_y();
}

void Rectangle::display()
{
    cout << "Rectangle Name: " << this->getName() 
    << "\nX-Coordinate: "<< get_rectX() 
    << "\nY-Coordinate: " << get_rectY()
    << "\nSide a: "<<side_a
    <<"\nSide b: "<< side_b
    <<"\nArea: "<< Rec_area() 
    << "\nPerimeter: " << Rec_perimeter()
            <<std::endl;
}



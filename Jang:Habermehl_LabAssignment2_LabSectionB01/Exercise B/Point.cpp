/*
* File Name: Point.cpp
* Assignment: Lab 2 Exercise B
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 2, 2023
*/


#include "Point.h"

int Point::count = 0; 

Point::Point(double cord_x, double cord_y) {
        x = cord_x;
        y = cord_y;
        id = 1000;
        id  = counter();
}



Point& Point::operator =( Point& rhs){
	if(this != &rhs){
		x = rhs.x;
		y = rhs.y;
	}
	return *this;
}

//Getters
double Point::get_x()const{
    return x;
}

double Point::get_y()const{
    return y;
}
const int Point::get_ID(){
    return id;
}

//Setters
void Point::setx(double setter){
    x = setter;
}

void Point::set_y(double setter){
    y = setter;
}

double Point::counter(){
    count++;
    id = 1000+count;
    return id;
}

double Point::distance(Point& other) {
    double dx = x - other.get_x();
    double dy = y - other.get_y();
    return sqrt((dx * dx) + (dy * dy));
    
}

double Point::distance(Point x1, Point y1) {
    double dx = x1.get_x() - y1.get_x();
    double dy = x1. get_y() - y1.get_y();
    return sqrt((dx * dx) + (dy * dy));
}


void Point::display(){
    printf("\nX-coordinate: %.2f", x);
    printf("\nY-coordinate: %.2f\n", y);
}




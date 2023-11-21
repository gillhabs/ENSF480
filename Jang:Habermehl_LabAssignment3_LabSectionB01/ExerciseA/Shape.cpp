/*
* File Name: Shape.cpp
* Assignment: Lab 3 Exercise A
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 7, 2023
*/

#include "Shape.h"


Shape::Shape(const Point& p, const char* name) //constructor that initializes its data members
:origin(p)
{
    shapeName = new char[strlen(name) + 1];
    strcpy(shapeName, name);
} 

Shape::Shape(const Shape& other):origin(other.origin) //copy constructor
{
    shapeName = new char[strlen(other.shapeName) + 1];
    strcpy(shapeName, other.shapeName);
}

Shape& Shape::operator=(Shape& rhs)
{
	if(this==&rhs)
		return *this;
	if (strcmp(shapeName, rhs.shapeName) != 0) {
        delete[] shapeName;
        shapeName = new char[strlen(rhs.shapeName) + 1];
        if (shapeName == nullptr) {
            exit(1);
        }
        strcpy(shapeName, rhs.shapeName);
    }
    origin = rhs.origin;
    return *this;
}

Shape::~Shape(){
    delete[] shapeName;
}

//Getters
double Shape::get_x()const{
    return this->origin.get_x();
}

double Shape::get_y()const{
    return this-> origin.get_y();
}

char* Shape::getName()const{
    return shapeName;
}

Point& Shape::getOrigin(){
    return origin;
}

double Shape::distance(Shape& other) {
    Point org = other.getOrigin();
    return origin.distance(org);
    
}

double Shape::distance(Shape& the_shape, Shape& other) {
    Point org = other.getOrigin();
    return the_shape.getOrigin().distance(org);
}

void Shape::move (double dx, double dy){

    origin.setx(origin.get_x() + dx);
	origin.set_y(origin.get_y() + dy);
}


void Shape::display(){
    std::cout << "\nShape Name: " << shapeName << "\nX-Coordinate: "
              << origin.get_x() << "\nY-Coordinate: " << origin.get_y() << std::endl;
}

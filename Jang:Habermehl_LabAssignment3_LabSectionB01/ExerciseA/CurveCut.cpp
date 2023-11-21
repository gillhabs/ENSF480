/*
* File Name: CurveCut.cpp
* Assignment: Lab 3 Exercise A
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 7, 2023
*/

#include "CurveCut.h"

CurveCut::CurveCut(double C_x, double C_y, double length, double width, double C_radius, char const* name)
:Shape(Point(C_x, C_y), name), 
Circle(C_x, C_y, C_radius, name),
Rectangle(C_x, C_y, length, width, name) 
{
    if(C_radius > length || C_radius > width){
        cout << "Error: radius is greater than smallest rectangle length.\n"
                << "Terminating Program";
        exit(1);
	}
}


double CurveCut::get_radius(){
    return Circle::get_radius();
}

double CurveCut::getSideA(){
    return Square::getSideA();
}
    

double CurveCut::getSideB(){
    return Rectangle::Rec_getSideB();
}


double CurveCut::area(){
    double circle_area = (Circle::area())/4;
    // cout<<"\nHERE CIRCLE AREA: " << Rectangle::Rec_area();
    // cout<<"\n";
    return Rectangle::area() - circle_area;
}
double CurveCut::perimeter(){
    double circle_perimeter = (Circle::perimeter())/4;
    double circle_radius = (Circle::get_radius())*2;
    return Rectangle::perimeter() - circle_radius + circle_perimeter;

}

void CurveCut::display(){
    cout << "\nCurveCut Name: " << Shape::getName()
    << "\nX-Coordinate: "<< Rectangle::origin.get_x() 
    << "\nY-Coordinate: " << Rectangle::origin.get_y()
    <<"\nWidth: "<< Square::getSideA()
    << "\nLength: " << Rectangle::Rec_getSideB()
    << "\nRadius of the cut: "<<Circle::get_radius()
    
    <<std::endl;
}
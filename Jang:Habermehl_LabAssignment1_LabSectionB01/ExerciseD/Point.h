/*
* File Name: Point.h
* Assignment: Lab 1 Exercise D
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Sept 18, 2023
*/

#ifndef POINT_PROG
#define POINT_PROG

class Point{
    private:
        double x;     // x coordinate of a location on Cartisian Plain
        double y;     // y coordinate of a location on Cartisian Plain
    public:
        Point(); // Default constructor
        Point(double a =0, double b =0);
        double get_x()const;        // Getter                
        double get_y()const;       // Getter                       
        void set_x(double a); // Setter
        void set_y(double a); // Setter
};

#endif

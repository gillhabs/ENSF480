/*
* File Name: Point.h
* Assignment: Lab 2 Exercise B
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 2, 2023
*/

#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
using namespace std;


class Point{
    private:
        double x;
        double y;
        int id;
        static int count;
    public:
        Point(double cord_x, double cord_y); //Constructor that initalizes

        Point& operator =(Point& rhs);

        //getters
        double get_x()const;
        double get_y()const;
        const int get_ID();

        //Setters
        void setx(double x);
        void set_y(double y);
        
        double counter();

        //distance setters
        double distance(Point& other);
        static double distance(Point x1, Point y1);
        void display();
};

#endif



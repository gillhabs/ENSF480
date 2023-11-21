/*
* File Name: Human.h
* Assignment: Lab 1 Exercise D
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Sept 18, 2023
*/


#ifndef HUMAN_PROG
#define HUMAN_PROG
#include "Point.h"


class Human {
protected:
    Point location;   // Location of an object of Human on a Cartisian Plain
    char *name;       // Human's name
public:
    
    Human(const char* nam="", double x=0, double y=0); // Constructor
    Human(const Human& other); // Copy Constructor
    ~Human(); // Destructor
    char* get_name(); //Getter for name
    void set_name(char* name); //Setter
   
    Point get_point()const; // Getter for location
    void set_point(double x, double y); // Setter for location
    
    void display();
};

#endif

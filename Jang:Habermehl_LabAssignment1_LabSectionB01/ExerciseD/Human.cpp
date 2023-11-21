/*
* File Name: Human.cpp
* Assignment: Lab 1 Exercise D
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Sept 18, 2023
*/

#include <iostream>
#include <cstring>
#include "Human.h"

using namespace std;

// Constructor
Human::Human(const char* nam, double x, double y) : location(x, y), name(new char[strlen(nam) + 1]) {
    if (nam != nullptr) {
        name = new char[strlen(nam) + 1];
        strcpy(name, nam);
        location.set_x(x);
        location.set_y(y);
    }
}

Human::Human(const Human& other) // Copy constructor
    : name(nullptr), location(other.location.get_x(), other.location.get_y()) {
    if (other.name != nullptr) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
}

// Destructor
Human::~Human(){
    delete[] name;
}

// Getter for name
char* Human::get_name() {
    return name;
}

// Setter for name
void Human::set_name(char* name) { // this
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// Getter for location
Point Human::get_point() const {
    return location;
}

//Setter for location
void Human::set_point(double x, double y) {
    location.set_x(x);
    location.set_y(y);
}


// Display information
void Human::display() {
    std::cout << "Human Name: " << name << "\nHuman Location: "
              << location.get_x() << ", " << location.get_y() << ".\n" << std::endl;
}
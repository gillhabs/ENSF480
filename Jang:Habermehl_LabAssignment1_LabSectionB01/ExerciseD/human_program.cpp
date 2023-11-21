/*
* File Name: human_program.cpp
* Assignment: Lab 1 Exercise D
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Sept 18, 2023
*/

#include "Human.h"
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	double x = 2000, y = 3000;
	Human h("Ken Lai", x , y); 
    h.display();
	return 0;
}


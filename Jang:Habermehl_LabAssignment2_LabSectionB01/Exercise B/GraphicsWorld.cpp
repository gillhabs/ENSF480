/*
* File Name: GraphicsWorld.cpp
* Assignment: Lab 2 Exercise B
* Completed by: Grace Jang and Gillian Habermehl
* Submission Date: Oct 2, 2023
*/

#include "GraphicsWorld.h"

void GraphicsWorld::run(){
    cout<<"This program was written by Grace Jang and Gillian Habermehl"
    <<"\nThe changes made comparing the given GraphicsWorld and our modified"
    <<"\nis a more through testing of the functions such as assignment operator "
    <<"\nand copy constructor\n"
    <<"/.........................................../\n";
#if 1 // Change 0 to 1 to test Point
    Point m (6, 8);
    cout << "\nExpected Point m \nX-coordinate: 6.00 \nY-coordinate: 8.00";
    cout << "\nResult of testing Point m";
    m.display();
    Point n (6,8);
    cout << "\nExpected Point n \nX-coordinate: 6.00 \nY-coordinate: 8.00";
    cout << "\nResult of testing Point n";
    n.display();
    n.setx(9);
    cout << "\nExpected Point n \nX-coordinate: 9.00 \nY-coordinate: 8.00";
    cout << "\nResult of testing Point n";
    n.display();
    cout << "\nExpected to diplay the distance between m and n is: 3";
    cout << "\nThe distance between m and n is: " << m.distance(n);
    cout << "\nExpected second version of the distance function also print: 3";
    cout << "\nThe distance between m and n is again: " << Point::distance(m, n);
    cout <<"\nThe id for m:"<< m.get_ID();
    cout <<"\nThe id for n:"<< n.get_ID();

#endif // end of block to test Point
#if 1 // Change 0 to 1 to test Square
    cout << "\n\nTesting Functions in class Square:" <<endl;
    Square s(5, 7, 12, "SQUARE - S");
    cout <<"\nExpected output of square s: \nSquare Name: SQUARE - S \nX-Coordinate: 5 \nY-Coordinate: 7 \nSidea: 12 \nArea: 144 \nPerimeter: 48";
    cout<<"\nResult of Testing: \n";
    s.display();
    s.setSideA(7);
    cout <<"\nExpected output of square s: \nSquare Name: SQUARE - S \nX-Coordinate: 5 \nY-Coordinate: 7 \nSide a: 7 \nArea: 49 \nPerimeter: 28";
    cout<<"\nResult of Testing: \n";
    s.display();

#endif // end of block to test Square
#if 1 // Change 0 to 1 to test Rectangle
    cout << "\nTesting Functions in class Rectangle:";
    Rectangle a(5, 7, 12, 15, "RECTANGLE A");
    a.display();
    Rectangle b(16 , 7, 8, 9, "RECTANGLE B");
    b.display();

    double d = a.distance(b);
    cout <<"\nDistance between square a, and b is: " << d << endl;
    cout<<"\n/.........................................../\n";

    cout << "\nTesting assignment operator and Copy Consturctor in class Rectangle:" <<endl;
    cout << "\nNew object rec1 is assigned rectangle a values"<<endl;
    a.display();
    Rectangle rec1 = a;
    cout << "\nrec1 assigned as a"<<endl;
    rec1.display();
    cout<<"\n/.........................................../\n";

    cout << "\nTesting assignment operator in class Rectangle:" <<endl;
    Rectangle rec2 (3, 4, 11, 7, "RECTANGLE rec2");
    rec2.display();
    rec2 = a;

    cout<<"\n/.........................................../\n";

    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n" << "X-coordinate: 5\n" << "Y-coordinate: 7\n"
    << "Side a: 12\n" << "Side b: 15\n" << "Area: 180\n" << "Perimeter: 54\n" ;
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n" << endl;
    cout << "\nThis is the output from my code and should match the expected that is listed above\n";
    rec2.display();
    cout<<"\n/.........................................../\n";

    cout << "\nNow testing copy constructor in class Rectangle:" <<endl;
    a.set_side_b(200);
    a.set_side_a(100);
    Rectangle rec3(a);
    cout<<"\nThis is my output"<<endl;
    rec3.display();

    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n" << "X-coordinate: 5\n" << "Y-coordinate: 7\n"
    << "Side a: 100\n" << "Side b: 200\n" << "Area: 20000\n" << "Perimeter: 600\n" ;
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n" << endl;
    cout<<"\n/.........................................../\n";
    cout<<"\nRec 3 display"<<endl;
    rec3.display();
    cout << "\nSetter Tester using rec3"<<endl;
    rec3.set_side_b(300);
    rec3.set_side_a(400);
    cout << "Rectangle Name: RECTANGLE A\n" << "X-coordinate: 5\n" << "Y-coordinate: 7\n"
    << "Side a: 400\n" << "Side b: 300\n" << "Area: 120000\n" << "Perimeter: 1400\n" ;
    cout<<"\nThis is my output"<<endl;
    rec3.display();
    cout<<"\n/.........................................../\n";

#endif // end of block to test Rectangle
#if 1 // Change 0 to 1 to test using array of pointer and polymorphism
    cout << "\nTesting array of pointers and polymorphism:" <<endl;
    Shape* sh[4];
    sh[0] = &s;
    sh[1] = &b;
    sh [2] = &rec1;
    sh [3] = &rec3;
    sh [0]->display();
    sh [1]->display();
    sh [2]->display();
    sh [3]->display();
    cout<<"\n/.........................................../\n";
#endif // end of block to test array of pointer and polymorphism

#if 1 //testing class Shape
    cout << "\nTesting Functions in class Shape:";
    Shape happy(Point(7,9), "Happy Shape");
    cout<<"\n";
    happy.display();
    cout<<"\nTesting Move function: \nX coordinate should be moved +3 and y coordinate should be move +4"<<endl;
    happy.move (3, 4);
    happy.display();
    cout<<"\nTesting assignment operator"<<endl;
    Shape open(Point(19,4), "Open Shape");
    open.display();
    open = happy;
    open.display();
    cout<<"\nTesting copy constructor for object copy_1 from object open"<<endl;
    Shape copy_1(open);
    copy_1.display();
    cout<<"\nTesting distance function\nX "<<endl;
    cout << "\nThe distance between m and n is again: " << Shape::distance(happy, open);
    Shape sad(Point(14,20), "Sad Shape");
    cout << "\nThe distance between m and n is again: " << Shape::distance(happy, sad);
#endif
}

int main(){
	GraphicsWorld output_run = GraphicsWorld();
	output_run.run(); 
	return 0;
}
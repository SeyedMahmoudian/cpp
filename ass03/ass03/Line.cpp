/**************************************************
Filename: Line.cpp
Version: 1.0
Author: Seyedamin Seyedmahmoudian
Student Number: 040-813-340
Course Name and Number: C++ Programming - CST8219
Lab Section: 300
Assignment Number : 3
Assignment Name : Vector Graphic with Polymorphic Inheritance and Templates
Due Date : 2016-12-03
Submission Date : 2016-12-03
Professor's Name : Andrew Tyler
****************************************************/
#include <vector>
#include <list>
#include <deque>
#include <iostream>
using namespace std;
#include "Pair.h"
#include "Shape.h"
#include "Line.h"
/**************************************************
Function name:		CalculateCentre()
Purpose:			calculate center for the line object
In parameters:		none
Out parameters:		pair
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
Pair Line :: CalculateCentre(){
	
	return (p1 + p2) / 2;
	
}
/**************************************************
Function name:		Report()
Purpose:			report function for shape line
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
void Line :: Report(){
	cout << "Shape LINE" << name << endl;
	cout <<"start coordinates:",p1.Report();
	cout << "end coordinates:",p2.Report();
}
/**************************************************
Filename: Rectangle.cpp
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
#include <iostream>
using namespace std;
#include "Pair.h"
#include "Shape.h"

#include "Rectangle.h"

#include "GraphicElement.h"
#include "VectorGraphic.h"

/**************************************************
Function name:		CalculateCentre()
Purpose:			calculate center for the Rectangle object
In parameters:		none
Out parameters:		Pair
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/

Pair Rectangle::CalculateCentre(){
		
	return (p1 + p2) / 2;

}
/**************************************************
Function name:		Report()
Purpose:			report function for Rectangle 
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
void Rectangle::Report(){
	cout << "Shape RECTANGLE" << name << endl;
	cout << "start coordinates:",p1.Report();
	cout << "end coordinates:",p2.Report();
}
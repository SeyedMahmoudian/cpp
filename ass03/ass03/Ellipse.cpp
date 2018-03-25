/**************************************************
Filename: Ellipse.cpp
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
#include <vector>
#include <list>
#include <deque>
#include <iostream>
using namespace std;
#include "Pair.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"


/**************************************************
Function name:		CalculateCentre()
Purpose:			calculate center for the Ellipse object
In parameters:		none
Out parameters:		Pair
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
Pair Ellipse::CalculateCentre(){

	return p1;

}
/**************************************************
Function name:		Report()
Purpose:			report function for Ellipse 
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
void Ellipse::Report(){
	cout << "Shape ELLIPSE" << name << endl;
	cout << "centre coordinates" , p1.Report();
	cout << "axes dimensions: " ,p2.Report();
}

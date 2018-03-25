/**************************************************
Filename: Pair.cpp
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
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"
/**************************************************
Function name:		 operator+
Purpose:			add 2 point and return the result
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
Pair Pair::operator+(Pair &temp){
	Pair temp2;
	temp2.x = temp.x + x;
	temp2.y = temp.y + y;
	return temp2;
}
/**************************************************
Function name:		 operator/
Purpose:			devide 2 point and return the result
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
Pair Pair::operator/(double num){
	Pair temp2;
	temp2.x = x / num;
	temp2.y = y / num;
	return temp2;
}
/**************************************************
Function name:		 Report()
Purpose:			report x and y
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
void Pair::Report(){
	cout << "x="<< x << "y="<< y << endl;
}

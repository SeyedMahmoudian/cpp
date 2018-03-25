/**************************************************
Filename: VectorGraphic.cpp
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
Purpose:      Add new Graphic Element
****************************************************/
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#include "Pair.h"
#include "Shape.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"

/**************************************************
Function name:		VectorGraphic()
Purpose:			default constructor with no body
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
VectorGraphic::VectorGraphic(){
}
/**************************************************
Function name:		~VectorGraphic()
Purpose:			destructor to release memory
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
VectorGraphic::~VectorGraphic(){

	for (unsigned int i = 0; i < size(); i++){
		delete[]this;
	}
	clear();
}
/**************************************************
Function name:		AddGraphicElement()
Purpose:			add new shape to graphic element array
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
void VectorGraphic::AddGraphicElement(){
	int size = 0;
	char name[256];
	char shapeName[256];
	int shapeNum = 0;
	char type=0;
	Shape**shape;
	double startX=0.0, startY=0.0,endX=0.0,endY=0.0;
	cout << "Adding A Graphic Element\n" << endl;
	cout << "Please enter the name of the new GraphicElement(<256 characters): ";
	cin >> name;
	cout << "Please enter the number of Shapes it contains:";
	cin >> shapeNum;
	shape = new Shape*[shapeNum];
	size = shapeNum--;

	for (int i = 0; i < size; i++){
		cout << "Please enter the type (L for line, R for rectangle, E for ellipse) for Shape# " << i << ":";
		cin >> type;
		switch (type){
		case 'L':
			cout << "Please enter the name of the new Line(<256 characters)";
			cin >> shapeName;
			cout << "please enter the coordinates of the start point: (x,y)" << endl;
			cin >> startX;
			cin >> startY;
			cout << "please enter the coordinates of the end point: (x,y)" << endl;
			cin >> endX;
			cin >> endY;
				*shape=new Line(shapeName, Pair(startX, startY), Pair(endX,endY));
			break;
		case 'R':
			cout << "Please enter the name of the new Rectangle(<256 characters):" << endl;
			cin >> shapeName;
			cout << "please enter the coordinates of the top-left: (x,y)" << endl;
			cin >> startX;
			cin >> startY;
			cout << "please enter the coordinates of the bottom-right: (x,y)" << endl;
			cin >> endX;
			cin >> endY;
			*shape = new Rectangle(shapeName, Pair(startX, startY), Pair(endX, endY));
			
			break;
		case 'E':
			cout << "Please enter the name of the new Ellipse(<256 characters):" << endl;
			cin >> shapeName;
			cout << "please enter the coordinates of the centre: (x,y)" << endl;
			cin >> startX;
			cin >> startY;
			cout << "please enter the width and height: (width, height)" << endl;
			cin >> endX;//use this as w
			cin >> endY;//use this as h
			*shape = new Ellipse(shapeName, Pair(startX,startY), Pair(endX,endY));
			break;
		default:cout << "Please enter a valid option\n";
		}
	
	}
	GraphicElement graph(shape,shapeName, shapeNum);
	push_back(graph);
	delete[]shape;
}
/**************************************************
Function name:		AddGraphicElement()
Purpose:			delete graphic element from specific position of array
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
void VectorGraphic::DeleteGraphicElement(){
	int index = 0;
	cout << "Deleting a Graphic Element"<<endl;
	
	cout << "Please enter the index to delete in the range",begin(), "to",end();
	cin >> index;
	erase(begin()+index);
	cout << "erase index" << index << endl;
}
/**************************************************
Function name:		 operator<<
Purpose:			This function will simply display all the Graphic Elemenets once it has been called
by the main function.
In parameters:		ostream, VectorGraphic
Out parameters:		ostream
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
ostream & operator<<(ostream& os, VectorGraphic & temp){
	os << "VectorGraphic Report" << endl;
	for (unsigned int i = 0; i < temp.size(); i++){
		os << "Reporting Graphic Element " << i << endl;
		os<<temp[i];
	}
	return os;	
}

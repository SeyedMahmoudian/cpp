/**************************************************
Filename: VectorGraphic.cpp
Version: 2.0
Author: Seyedamin Seyedmahmoudian
Student Number: 040-813-340
Course Name and Number: C++ Programming - CST8219
Lab Section: 300
Assignment Number : 2
Assignment Name : Vector Graphic with Overloaded Operators
Due Date : 2016-11-12
Submission Date : 2016-11-12
Professor's Name : Andrew Tyler
Purpose:      Add new Vector Graphic
****************************************************/
using namespace std;
#include <string>
#include <iostream>
#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"

VectorGraphic Image;
/**************************************************
Function name:		AddGraphicElement()
Purpose:			To add new points and lines to the graphic.
this function is the core function of this program it will first make sure that all the previous element
in main element has being copied to the temporary element and then it will free the primary element and if
necessary will increase the size of primary elemenet then it will copy back all the element from temporary
element back to the orginal element.
Then it will prompt the client for name of the graphic element and how many elements they would like to add ,
once user input their desired number for the size of the graphic elements it will start asking the user to populate the graphic elements by X and Y points
In parameters:		none
Out parameters:		void
Version:			3.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
void VectorGraphic::AddGraphicElement(){
	int size = 0;
	char* name=0;
	int lineNum = 0;
	int x, y;

	Line *pLines=NULL;

	cout << "Adding A Graphic Element\n" << endl;
	numGraphicElements++;
	cout << "Please enter the name of the new GraphicElement(<256 characters): ";
	cin >> name;
	cout << "How many lines are there in the  new GraphicElement?";
	cin >> lineNum;
	size = lineNum - 1;
	
	for (int j = 0; j < size; j++){
		cout << endl << "Please enter the x coord of the start point of line index " << j << ": ";
		cin >> x;
		cout << endl << "Please enter the y coord of the start point of line index " << j << ": ";
		cin >> y;
		Point point(x, y);
		cout << endl << "Please enter the x coord of the end point of line index " << j << ": ";
		cin >> x;
		cout << endl << "Please enter the y coord of the end point of line index " << j << ": ";
		cin >> y;
		Point secPoint(x, y);

		pLines = new Line(point, secPoint);
	}
	numGraphicElements++;
	GraphicElement graph(pLines, name, lineNum);
	*this += graph;

}
/**************************************************
Function name:		DeleteGraphicElement()
Purpose:			This new function will allow user to delete an specific element in the desired index of Graphic Element
once the desired element was deleted from the Graphic Element it will re-arrange the array and fix
the sequence.
In parameters:		none
Out parameters:		void
Version:			2.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
void VectorGraphic::DeleteGraphicElement(){
	int index = 0;
	GraphicElement *temp=new GraphicElement[numGraphicElements-1];
	cout << "Deleting a Graphic Element" << endl;
	cout << "Please enter the index of the Graphic Element you wish to delete" << endl;
	cin >> index;
	for (int i = 0; i < index; i++){
		temp[i] = pElements[i];
	}
	for (int i = index; i < numGraphicElements; i++){
		temp[i] = pElements[i+1];
	}
	numGraphicElements--;
	delete[]pElements;
	pElements = temp;
}
/**************************************************
Function name:		operator+=
Purpose:		
In parameters:		GraphicElement &
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
void VectorGraphic :: operator+=(GraphicElement &temp){
	
	GraphicElement *tempElements = new GraphicElement[numGraphicElements + 1];
	for(unsigned int i = 0; i < numGraphicElements; i++){
		tempElements[i] = pElements[i];
	}
	tempElements[numGraphicElements+1] = temp;
	delete[]pElements;
	pElements = tempElements;
	
}
/**************************************************
Function name:		operator[]
Purpose:
In parameters:		int
Out parameters:		GraphicElement &
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
GraphicElement & VectorGraphic::operator[](int index){
	return pElements[index];
}
/**************************************************
Function name:		operator<<
Purpose:
In parameters:		ostream& , VectorGraphic &
Out parameters:		ostream
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
ostream & operator<<(ostream& os, VectorGraphic & vector){
	os << "Reporting Graphic Element:" << vector.numGraphicElements;

	return os;
}



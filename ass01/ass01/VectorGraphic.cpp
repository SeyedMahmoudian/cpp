/**************************************************
Filename: VectorGraphic.cpp
Version: 1.0
Author: Seyedamin Seyedmahmoudian
Student Number: 040-813-340
Course Name and Number: C++ Programming - CST8219
Lab Section: 300
Assignment Number : 1
Assignment Name : Vector Graphic in C++
Due Date : 2016-10-15
Submission Date : 2016-10-13
Professor's Name : Andrew Tyler
Purpose:           This program will allow the client to:
- Add new graphic element to the Vector Graphic.
- Print all the details of the Graphic Elements in the Vector Graphic.
- Delete a Graphic Element leaving no unused space in dynamic memory.
The purpose of this program is to create an array of Graphic Elemenets, each  elements is made of Lines and Points.
****************************************************/

using namespace std;
#include <string>
#include <iostream>
#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"
void AddGraphicElement();
void ReportVectorGraphic();
void DeleteGraphicElement();
VectorGraphic Image;
/**************************************************
Function name:		VectorGraphic()
Purpose:			Constructor to set all the values to zero and null
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/

VectorGraphic::VectorGraphic(){
	numGraphicElements = 0;
	pElements = nullptr;
}
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
Version:			2.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
void VectorGraphic::AddGraphicElement(){
	int size = 0;
	
	GraphicElement *tempElements = new GraphicElement[numGraphicElements + 1];
	
	for (int i = 0; i < numGraphicElements; i++){
		tempElements[i].numLines = pElements[i].numLines;
		tempElements[i].pLines=new Line[tempElements[i].numLines];
		strcpy(tempElements[i].name, pElements[i].name);
	
		for ( int j = 0; j < pElements[i].numLines;j++){
			tempElements[i].pLines[j] = pElements[i].pLines[j];
		}	
	}
	delete[]pElements;
	pElements = tempElements;
	cout << "Adding A Graphic Element\n" << endl;
	numGraphicElements++;
	cout << "Please enter the name of the new GraphicElement(<256 characters): " ;
	cin >> pElements[numGraphicElements-1].name;
	cout << "\nHow many lines are there in the  new GraphicElement? " ;
	cin >> pElements[numGraphicElements-1].numLines;
	size = (pElements[(numGraphicElements-1)].numLines);	
	pElements[numGraphicElements-1].pLines = new Line[size];

	for (int j = 0; j < size; j++){
		cout << endl << "Please enter the x coord of the start point of line index " <<j<<": ";
		cin >>pElements[numGraphicElements - 1].pLines[j].start.x;	
		cout << endl << "Please enter the y coord of the start point of line index " <<j<<": ";
		cin >> pElements[numGraphicElements - 1].pLines[j].start.y;
		cout << endl << "Please enter the x coord of the end point of line index " <<j<<": ";
		cin >> pElements[numGraphicElements - 1].pLines[j].end.x;
		cout << endl << "Please enter the y coord of the end point of line index " <<j<<": ";
		cin >> pElements[numGraphicElements - 1].pLines[j].end.y;
		
	
	}
}
/**************************************************
Function name:		ReportVectorGraphic()
Purpose:			This function will simply display all the Graphic Elemenets once it has been called     
                    by the main function.
In parameters:		none
Out parameters:		void
Version:			2.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
void VectorGraphic::ReportVectorGraphic(){
	cout << "VectorGraphic Report" << endl;
	int size = 0;
	for (int i = 0; i < numGraphicElements; i++){
		size = pElements[i].numLines;
		cout << endl << "Report Graphic Element" << i << endl;
		cout << endl << "Graphic Element name: " << pElements[i].name << endl;
		for ( int j = 0; j < pElements[i].numLines; j++)
		{
			cout << "Line " << j << " start x:" << pElements[i].pLines[j].start.x << endl;
			cout << "Line " << j << " start y:" << pElements[i].pLines[j].start.y  << endl;
			cout << "Line " << j << " end x:" << pElements[i].pLines[j].end.x << endl;
			cout << "Line " << j << " end y:" << pElements[i].pLines[j].end.x << endl;
		}
	}
}
/**************************************************
Function name:		DeleteGraphicElement()
Purpose:			This new function will allow user to delete an specific element in the desired index of Graphic Element
						 once the desired element was deleted from the Graphic Element it will re-arrange the array and fix
						 the sequence.
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
void VectorGraphic::DeleteGraphicElement(){
	int index = 0;
	GraphicElement *tempElements = new GraphicElement[numGraphicElements - 1];
	cout << "Deleting a Graphic Element" << endl;
	cout << "Please enter the index of the Graphic Element you wish to delete" << endl;
	cin >> index;
	for (int i = 0; i < index; i++){

		tempElements[i].numLines = pElements[i].numLines;
		tempElements[i].pLines = new Line[tempElements[i].numLines];
		strcpy(tempElements[i].name, pElements[i].name);

		for (int j = 0; j < pElements[i].numLines; j++){
			tempElements[i].pLines[j] = pElements[i].pLines[j];
		}
	}
	for (int i = index; i < numGraphicElements-1; i++){

		tempElements[i].numLines = pElements[i + 1].numLines;
		tempElements[i].pLines = new Line[tempElements[i].numLines];
		strcpy(tempElements[i].name, pElements[i + 1].name);

		for (int j = 0; j < pElements[i + 1].numLines; j++){
			tempElements[i].pLines[j] = pElements[i + 1].pLines[j];
		}
}
		numGraphicElements--;
		delete[]pElements;
		pElements = tempElements;

	
}
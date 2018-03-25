/**************************************************
Filename: GraphicElement.cpp
Version: 1.0
Author: Seyedamin Seyedmahmoudian
Student Number: 040-813-340
Course Name and Number: C++ Programming - CST8219
Lab Section: 300
Assignment Number : 2
Assignment Name : Vector Graphic with Overloaded Operators
Due Date : 2016-11-12
Submission Date : 2016-11-12
Professor's Name : Andrew Tyler
Purpose:      Add new Graphic Element
****************************************************/
using namespace std;
#include <string>
#include <iostream>
#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"


GraphicElement :: GraphicElement(Line *tempLines, char* tempName, unsigned int tempSize){
	pLines = tempLines;
	numLines = tempSize;
	strcpy_s(name,tempName);

}
GraphicElement::GraphicElement(GraphicElement &tempGraph){//copy constructor
	numLines = tempGraph.numLines;
	strcpy_s(name, tempGraph.name);
	pLines = new Line[tempGraph.numLines];
	for (unsigned int i = 0; i < tempGraph.numLines; i++){
		pLines[i] = tempGraph.pLines[i];
	}
}
GraphicElement& GraphicElement::operator=(GraphicElement& temp){
	delete[]pLines;
	numLines = temp.numLines;
	strcpy_s(name, temp.name);
	pLines = new Line[temp.numLines];
	memcpy(pLines,temp.pLines,sizeof(Line)*numLines);
	return *this;
}
GraphicElement GraphicElement::operator+(GraphicElement& temp){
	GraphicElement temp2;
	temp2.numLines = temp.numLines + numLines;
	strcpy_s(temp2.name, temp.name);
	temp2.pLines = new Line[temp2.numLines];
	for (unsigned int i = 0; i < temp2.numLines; i++){
		temp2.pLines[i] = temp.pLines[i];
	}
	
	return temp2;
}

ostream & operator<<(ostream& os, GraphicElement& graphic){
	os << "Graphic Element name:" << graphic.name;
	os << "Line" << graphic.numLines;
	return os;
}

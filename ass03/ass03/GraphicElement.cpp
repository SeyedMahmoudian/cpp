/**************************************************
Filename: GraphicElement.cpp
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
#define _CRT_SECURE_NO_WARNINGS
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

typedef vector<Shape*> Container;
typedef Container::iterator Iter;
/**************************************************
Function name:		~GraphicElement
Purpose:			destructor to release memory
In parameters:		none
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
GraphicElement :: ~GraphicElement(){

	for (Iter i = begin(); i != end(); i++){
		delete(*i);
	}
	clear();
}
/**************************************************
Function name:		GraphicElement
Purpose:			initilizer 
In parameters:		Shape**,char*,unsigned int
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/

GraphicElement::GraphicElement(Shape** tempShape, char*tempName, unsigned int tempSize){//default constructor

	strcpy(name, tempName);
	for (unsigned int i = tempSize; i <= tempSize; i++){
		push_back(tempShape[i]);
	}


}
/**************************************************
Function name:		GraphicElement
Purpose:			initilizer
In parameters:		GraphicElement &
Out parameters:		void
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
GraphicElement::GraphicElement(const GraphicElement & graphic){//copy constructor
	Line* line;
	Rectangle * rec;
	Ellipse * elip;
	strcpy(name, graphic.name);

	for (const_iterator i = graphic.begin(); i != graphic.end(); i++){
		line = static_cast<Line*>(*i);
		if (line != nullptr){
			push_back(line);
		}
		else{
			rec = static_cast<Rectangle*>(*i);
			if (rec != nullptr){
				push_back(rec);
			}
			else{
				elip = static_cast<Ellipse*>(*i);
				if (elip != nullptr){
					push_back(elip);
				}

			}
		}

	}
}

/**************************************************
Function name:		operator=
Purpose:			overloaded operator
In parameters:		GraphicElement &
Out parameters:		GraphicElement object
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
GraphicElement& GraphicElement::operator=(GraphicElement& graphic){
	
	Line* line;
	Rectangle * rec;
	Ellipse * elip;
	line->~Line();
	rec->~Rectangle();
	elip->~Ellipse();
	strcpy(name, graphic.name);
	for (const_iterator i = graphic.begin(); i != graphic.end(); i++){
		line = static_cast<Line*>(*i);
		if (line != nullptr){
			push_back(line);
		}
		else{
			rec = static_cast<Rectangle*>(*i);
			if (rec != nullptr){
				push_back(rec);
			}
			else{
				elip = static_cast<Ellipse*>(*i);
				if (elip != nullptr){
					push_back(elip);
				}

			}
		}
	}
	return *this;

}
/**************************************************
Function name:		 operator<<
Purpose:			This function will simply display all the Graphic Elemenets once it has been called
In parameters:		ostream, GraphicElement
Out parameters:		ostream
Version:			1.0
Author:				Seyedamin Seyedmahmoudian
****************************************************/
ostream & operator<<(ostream& os, GraphicElement&temp){
	Pair centre;
	os << "Graphic Element name: " << temp.name << endl;
	for (GraphicElement::iterator j = temp.begin(); j != temp.end(); j++){
		centre = centre + (*j)->CalculateCentre();
	
	}
	centre = centre / temp.size();
	centre.Report();
	for (Iter i = temp.begin(); i != temp.end(); i++){
		(*i)->Report();
	}

	return os;
}
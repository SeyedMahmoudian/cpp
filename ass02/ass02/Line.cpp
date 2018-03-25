using namespace std;
#include <string>
#include <iostream>
#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"

ostream& operator<<(ostream& os, Line& line){
	
	os << "start Point"<<line.start;
	os << "end point"<<line.end;
	return os;
}
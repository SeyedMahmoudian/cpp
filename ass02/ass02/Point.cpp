using namespace std;
#include <string>
#include <iostream>
#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"

ostream& operator<<(ostream& os, Point& point){
	os << "Point: " << point.x << ";" << point.y;
	return os;
}
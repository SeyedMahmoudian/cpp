// Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle :public Shape
{
public:
	Rectangle(char* name, Pair topLeft, Pair bottomRight) :Shape(name, topLeft, bottomRight){};
	~Rectangle(){}
	Pair CalculateCentre();
	void Report();
};
#endif// !RECTANGLE_H
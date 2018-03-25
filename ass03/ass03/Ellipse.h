// Ellipse.h
#ifndef ELLIPSE_H
#define ELLIPSE_H
class Ellipse :public Shape
{
public:

	Ellipse::Ellipse(char* name, Pair centre, Pair axes) :Shape(name, centre, axes){}
	~Ellipse(){}
	Pair CalculateCentre();
	void Report();
}; 
#endif //! ELIPSE_H
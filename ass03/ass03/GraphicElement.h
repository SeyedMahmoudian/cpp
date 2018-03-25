// GraphicElement.h
#ifndef GRAPHIC_ELEMENT_H
#define GRAPHIC_ELEMENT_H

class GraphicElement : public vector<Shape*>
{
	static const int SIZE = 256;
	char name[SIZE];
public:
	GraphicElement(Shape**, char*, unsigned int);
	GraphicElement(const GraphicElement&);
	GraphicElement& operator=(GraphicElement&);
	~GraphicElement();
	friend ostream& operator<<(ostream&, GraphicElement&);
};
#endif // ! GRAHICPELEMENT_H
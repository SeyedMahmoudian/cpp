// VectorGraphic.h
#ifndef VECTOR_GRAPHIC_H
#define VECTOR_GRAPHIC_H

class VectorGraphic : public vector<GraphicElement>
{
public:
	VectorGraphic();
	~VectorGraphic();
	void AddGraphicElement();
	void DeleteGraphicElement();
	friend ostream& operator<<(ostream&, VectorGraphic&);
};
#endif //! VECTORGRAPHIC_H
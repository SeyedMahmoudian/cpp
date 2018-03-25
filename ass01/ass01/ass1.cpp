//ass1.cpp

#include <iostream>
using namespace std;

#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"

enum{ RUNING = 1 };

int main(){

	char response;
	VectorGraphic Image;

	while (RUNING)
	{
		cout << endl << "Please select an option:" << endl;
		cout << endl << "1.Add a Graphic Element" << endl;
		cout << endl << "2. Delete a Graphic Elemnet" << endl;
		cout << endl << "3. List the Graphic Element" << endl;
		cout << endl << "q. Quit" << endl;
		cout << "CHOICE: ";
		cin >> response;

		switch (response)
		{
		case '1': Image.AddGraphicElement(); break;
		case '2': Image.DeleteGraphicElement(); break;
		case '3': Image.ReportVectorGraphic(); break;
		case'q':  return 0;
		default: cout << "Please enter a valid option\n";
		}
		cout << endl;
	}

}

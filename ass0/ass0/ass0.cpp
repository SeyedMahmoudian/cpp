/**************************************************
Filename: ass0.cpp
Version: 1.0
Author: Seyedamin Seyedmahmoudian
Student Number: 040-813-340
Course Name and Number: C++ Programming - CST8219
Lab Section: 300
Assignment Number : 0
Assignment Name : Vector Graphic
Due Date : 2016-09-25
Submissino Date : 2016-09-22
Professor's Name : Andrew Tyler
Purpose:           This program will allow the client to:
                        - Add new graphic element to the Vector Graphic.
                        - Print all the details of the Graphic Elements in the Vector Graphic.
                    The purpose of this program is to create an array of Graphic Elemenets, each  elements is made of Lines and Points.
****************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<crtdbg.h>
#include <string.h>

#define _CRTBG_MAP_ALLOC


enum{ RUNNING = 1 };

struct Point
{
	int x, y;
};

struct Line
{
	Point start;
	Point end;
};

struct GraphicElement
{
	enum{ SIZE = 256 };
	unsigned int numLines;
	Line* pLines;
	char name[SIZE];
};

typedef struct
{
	unsigned int numGraphicElements;
	GraphicElement* pElements;
}VectorGraphic;

void InitVectorGraphic(VectorGraphic*);
void AddGraphicElement(VectorGraphic*);
void ReportVectorGraphic(VectorGraphic*);
void CleanUpVectorGraphic(VectorGraphic*);

VectorGraphic Image;
/**************************************************
 Function name:     main
 Purpose:           main function
                         Display the menu for client to choose from and base on the choose of the client will call the propar method
 In parameters:     none
 Out parameters:    0 for successful execution
 Version: 1.0
 Author: Andrew Tyler
****************************************************/

int main()
{
	char response;
	InitVectorGraphic(&Image);

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	while (RUNNING)
	{
		printf("\nPlease select an option:\n");
		printf("1. Add a Graphic Element\n");
		printf("2. List the Graphic Elements\n");
		printf("q. Quit\n");
		printf("CHOICE: ");
		fflush(stdin);
		scanf("%c", &response);

		switch (response)
		{
		case '1':AddGraphicElement(&Image); break;
		case '2':ReportVectorGraphic(&Image); break;
		case 'q':CleanUpVectorGraphic(&Image); return 0;
		default:printf("Please enter a valid option\n");
		}
		printf("\n");
	}
}
/**************************************************
 Function name:     InitVectorGraphic
 Purpose:           To initilize the vector graphic pointer
 In parameters:     Vector Graphic pointer
 Out parameters:    none
 Version: 1.0
 Author: Seyedamin Seyedmahmoudian
 ****************************************************/
void InitVectorGraphic(VectorGraphic* pImage){

	pImage->pElements = NULL;
	pImage->numGraphicElements = 0;


}
/**************************************************
 Function name:     AddGraphicElement
 Purpose:           To add new points and lines to the graphic.
                        this function is the core function of this program it will first make sure that all the previous element 
						in main element has being copied to the temporary element and then it will free the primary element and if 
						necessary will increase the size of primary elemenet then it will copy back all the element from temporary 
						element back to the orginal element. 
                    Then it will prompt the client for name of the graphic element and how many elements they would like to add , 
					once user input their desired number for the size of the graphic elements it will start asking the user to populate the graphic elements by X and Y points
 In parameters:     Vector Graphic pointer
 Out parameters:    none
 Version: 1.0
 Author: Seyedamin Seyedmahmoudian
 ****************************************************/

void AddGraphicElement(VectorGraphic* pImage){
	int i = 0;
	int size = 0;
	GraphicElement *tempElements;

	tempElements = (GraphicElement*)malloc(sizeof(GraphicElement)*(pImage->numGraphicElements + 1));

	for (i = 0; i < (pImage->numGraphicElements); i++)
	{
		tempElements[i] = pImage->pElements[i];
	}
	free(pImage->pElements);
	
	pImage->pElements = tempElements;


	printf("ADDING A Graphic Element\n");

	(pImage->numGraphicElements)++;

	printf("Please enter the name of the new GraphicElement(<256 characters):");
	scanf("%s", &(pImage->pElements[(pImage->numGraphicElements) - 1].name));
	printf("\nHow many lines are there in the  new GraphicElement?");
	scanf("%d", &(pImage->pElements[(pImage->numGraphicElements) - 1].numLines));

	size = (pImage->pElements[(pImage->numGraphicElements) - 1].numLines);

	pImage->pElements[(pImage->numGraphicElements) - 1].pLines = (Line*)malloc(sizeof (Line)*size);

	for (i = 0; i < size; i++){
		printf("Please enter the x coord of the start point of line index %d : ", i);
		fflush(stdin);
		scanf("%d", &(pImage->pElements[(pImage->numGraphicElements) - 1].pLines[i].start.x));
		printf("Please enter the y coord of the start point of line index %d : ", i);
		fflush(stdin);
		scanf("%d", &(pImage->pElements[(pImage->numGraphicElements) - 1].pLines[i].start.y));
		printf("Please enter the x coord of the end  point of line index %d : ", i);
		fflush(stdin);
		scanf("%d", &(pImage->pElements[(pImage->numGraphicElements) - 1].pLines[i].end.x));
		printf("Please enter the y coord of the end  point of line index %d :", i);
		fflush(stdin);
		scanf("%d", &(pImage->pElements[(pImage->numGraphicElements) - 1].pLines[i].end.y));


	}
	

}
/**************************************************
 Function name:     ReportVectorGraphic
 Purpose:           This function will simply display all the Graphic Elemenets once it has been called     
                            by the main function.
 In parameters:     Vector Graphic pointer
 Out parameters:    none
 Version: 1.0
 Author: Seyedamin Seyedmahmoudian
 ****************************************************/

void ReportVectorGraphic(VectorGraphic *pImage){
	int i = 0;
	int j = 0;
	printf("VectorGraphic Report");

	for (i = 0; i < pImage->numGraphicElements; i++)
	{
		printf("\nReporting Graphic Element #%d", i);
		printf("\nGraphic Element name: %s", pImage->pElements[i].name);

		for (j = 0; j < pImage->pElements[i].numLines; j++){
			printf("\nLine #%d start x: %d", j, pImage->pElements[i].pLines[j].start.x);
			printf("\nLine #%d start y: %d", j, pImage->pElements[i].pLines[j].start.y);
			printf("\nLine #%d end x:   %d", j, pImage->pElements[i].pLines[j].end.x);
			printf("\nLine #%d end y:   %d", j, pImage->pElements[i].pLines[j].end.y);
		}
	}


}
/**************************************************
 Function name:     CleanUpVectorGraphic
 Purpose:           This is the last that will be called from the main method, it will be called once 
                    the client input 'q' for their chose,then this function will simply free all 
                    pointers and the memory used by this application.
 In parameters:     Vector Graphic pointer
 Out parameters:    none
 Version: 1.0
 Author: Seyedamin Seyedmahmoudian
 ****************************************************/

void CleanUpVectorGraphic(VectorGraphic* pImage){

	free(pImage->pElements);

}

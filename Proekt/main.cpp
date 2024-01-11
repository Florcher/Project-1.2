#include <iostream>
#include "proekt.h"
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include "objectFactory.h"
#include "input.h"


void createBinaryObject() {

	int countOfObject = 3;

	std::ofstream fout("file2.txt", std::ios_base::binary);
	fout.write((char*)&countOfObject, 4);

	
	char ln[5] = "line";
	int id = 1;
	double xstart = -5;
	double ystart = -5;
	double xend = 5;
	double yend = 5;

	fout.write((char*)&ln, 5);
	fout.write((char*)&id, 4);
	fout.write((char*)&xstart, 8);
	fout.write((char*)&ystart, 8);
	fout.write((char*)&xend, 8);
	fout.write((char*)&yend, 8);

	char rec[10] = "rectangle";
	int id1 = 2;
	double xlefpoint = 0;
	double yleftpoint = 0;
	double lenth = 10;
	double width = 10;

	fout.write((char*)&rec, 10);
	fout.write((char*)&id1, 4);
	fout.write((char*)&xlefpoint,8);
	fout.write((char*)&yleftpoint, 8);
	fout.write((char*)&lenth, 8);
	fout.write((char*)&width, 8);

	char circ[7] = "circle";
	int id2 = 3;
	double xcenter = 1.4;
	double ycenter = 1.4;
	double radius = 17;

	fout.write((char*)&circ, 7);
	fout.write((char*)&id2, 4);
	fout.write((char*)&xcenter, 8);
	fout.write((char*)&ycenter, 8);
	fout.write((char*)&radius, 8);

	fout.close();

}


int main() {

	setlocale(LC_ALL, "ru");

	

	createBinaryObject();

	input* in = new inputOfBinaryFile;
	

	int countOfObject;
	in->inputCountOfobject(countOfObject);

	
	object** objects = new object * [countOfObject];


	in->inputObject(objects, countOfObject);



	for (int i = 0; i < countOfObject; i++) {
		objects[i]->print();
	}


	/*int iterator;

	input* in = new inputOfFile;

	in->inputCountOfobject(iterator);

	object** objects = new object * [iterator];

	in->inputObject(objects, iterator);


	for (int i = 0; i < iterator; i++) {
		objects[i]->print();
	}
	
	*/


	for (int i = 0; i < countOfObject; i++) {
		delete objects[i];
	}

	delete[] objects;
	
	
	return 0;
}


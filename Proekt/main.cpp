#include <iostream>
#include "proekt.h"
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include "objectFactory.h"
#include "input.h"





int main() {

	setlocale(LC_ALL, "ru");

	int iterator;



	input* in = new inputOfConsole;

	std::cout << "������� ���������� ��������" << std::endl;

	in->inputCountOfobject(iterator);


	object** objects = new object * [iterator];

	in->inputObject(objects, iterator);


	for (int i = 0; i < iterator; i++) {
		objects[i]->print();
	}
	

	for (int i = 0; i < iterator; i++) {
		delete objects[i];
	}

	delete[] objects;
	delete in;
	
	return 0;
}


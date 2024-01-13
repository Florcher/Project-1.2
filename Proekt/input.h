
#ifndef __INPUT_H_
#define __INPUT_H_

#include <iostream>
#include "proekt.h"
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include "objectFactory.h"
#include <stdio.h>
#include "inputChoice.h"
#include "inputObject.h"

class input {

public:

	void inputOf(std::istream& input, const int countOfObject, object** myObject) {

		objectFactory factory;
		inputChoice inputObject;

		for (int i = 0; i < countOfObject; i++) {

			inputObject.input(input);
			factory.createObject(inputObject, myObject, i);
		}

	}

	virtual void inputCountOfobject(int& iterator) {

	}

	virtual void inputObject(object** myObject, const int& countOfObject) {

	}


};

struct inputOfFile : public input {

public:

	

	void inputObject(object** myObject, const int& countOfObject) override {

		std::ifstream input;

		std::string path = "file.txt";
		input.open(path);

		int countOfObject_;
		input >> countOfObject_;

		input::inputOf(input, countOfObject, myObject);

		input.close();
	}
	
	void inputCountOfobject(int& countOfObject) override {

		std::ifstream input;

		std::string path = "file.txt";
		input.open(path);

		int countOfObject_;
		input >> countOfObject_;
		countOfObject = countOfObject_;

		input.close();
	}

};

struct inputOfConsole : public input {

public:


	void inputObject(object** myObject, const int& countOfObject) override {

		std::string path = "file1.txt";

		input::inputOf(std::cin, countOfObject, myObject);
	}

	void inputCountOfobject(int& countOfObject) override {

		int countOfObject_;
		std::cin >> countOfObject_;
		countOfObject = countOfObject_;
	}
};

struct inputOfBinaryFile : public input {


	void inputObject(object** myObject, const int& countOfObject) override {

		inputBinaryChoice inputBinary;
		objectFactory binarryFactor;

		int countOfObject_;
		std::ifstream fin("file2.txt", std::ios_base::binary);
		fin.read((char*)&countOfObject_, 4);

		for (int i = 0; i < countOfObject; i++) {

			
		
			std::vector<char> sym;
			sym.push_back('A');
			int iterator = 0;
			while (sym[iterator] != '\0') {
				char tmpSym;
				iterator++;
				fin.read((char*)&tmpSym, 1);
				sym.push_back(tmpSym);
			}

			std::string name;
			for (int i = 1; i < iterator; i++) {

				name.push_back(sym[i]);
			};

			int id;
			fin.read((char*)&id, 4);

			inputBinary.input(fin, name, id);
			binarryFactor.createObject(inputBinary, myObject, i);

		}
		
		
	}

	void inputCountOfobject(int& countOfObject) override {

		std::ifstream fin("file2.txt", std::ios_base::binary);
		fin.read((char*)&countOfObject, 4);
	}

};


#endif __INPUT_H__
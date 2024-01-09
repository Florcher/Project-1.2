#pragma once
#include <iostream>
#include "proekt.h"
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include "objectFactory.h"

class input {

public:

	void inputOf(std::istream& input, const int countOfObject, object** myObject) {

		objectFactory factory;

		std::vector<std::string> arrOfNameOfObject(countOfObject);
		std::vector<int> arrOfIndexOfObject(countOfObject);

		for (int i = 0; i < countOfObject; i++) {
			input >> arrOfNameOfObject[i];
			input >> arrOfIndexOfObject[i];

			factory.createObject(input, arrOfNameOfObject[i], arrOfIndexOfObject[i], myObject, i);
		}

	}

	virtual void inputCountOfobject(int& iterator) {

	}

	virtual void inputObject(object** myObject, const int& countOfObject) {

	}


};

struct inputOfFile : public input {

public:

	std::ifstream input;

	void inputObject(object** myObject, const int& countOfObject) override {

		std::string path = "file.txt";
		input.open(path);

		int countOfObject_;
		input >> countOfObject_;

		input::inputOf(input, countOfObject, myObject);

		input.close();
	}
	
	void inputCountOfobject(int& countOfObject) override {

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

	std::istream input;

	void inputObject(object** myObject, const int& countOfObject) override {

		std::string path = "file1.txt";

		input::inputOf(input, countOfObject, myObject);

		std::ofstream fout;
		fout.open(path, std::ofstream::app);

		for (int i = 0; i < countOfObject; i++) {
			fout.write((char*)&myObject[i], sizeof(myObject));

		}
	}

	void inputCountOfobject(int& countOfObject) override {

		int countOfObject_;
		input >> countOfObject_;
		countOfObject = countOfObject_;
	}
};
#ifndef __INPUTCHOICE_H_
#define __INPUTCHOICE_H_

#include <iostream>
#include <string>
#include <vector>
#include "proekt.h"
#include "inputObject.h"


struct buffer {

	virtual void input(std::istream& input) {};

	const std::string& getName() { return mName; };
	const int getId() { return mId; };
	const std::vector<vector2D>& getArrOfPoints() { return arrOfPoints; };
	const std::vector<double>& getOptions() { return options; };

	std::string mName;
	int mId;
	std::vector<vector2D> arrOfPoints;
	std::vector<double> options;
};



class inputBuffer : public buffer {

public:


	void input(std::istream& input) override {

		input >> mName;
		input >> mId;

		inputObject* inputobject;

		switch (mId) {

		case 1:
			arrOfPoints.clear();
			options.clear();
			inputobject = new inputLine;
			inputobject->input(input, arrOfPoints, options);
			delete inputobject;
			break;

		case 2:
			arrOfPoints.clear();
			options.clear();
			inputobject = new inputRectangle;
			inputobject->input(input, arrOfPoints, options);
			delete inputobject;
			break;

		case 3:
			arrOfPoints.clear();
			options.clear();
			inputobject = new inputCircle;
			inputobject->input(input, arrOfPoints, options);
			delete inputobject;
			break;

		case 4:
			arrOfPoints.clear();
			options.clear();
			inputobject = new inputPolyLine;
			inputobject->input(input, arrOfPoints, options);
			delete inputobject;
			break;

		default:
			break;
		}
	}

private:

};



class inputBinaryBuffer : public buffer {

public:

	void input(std::istream& fin) override {

		std::vector<char> sym;
		sym.push_back('A');
		int iterator = 0;
		while (sym[iterator] != '\0') {
			char tmpSym;
			iterator++;
			fin.read((char*)&tmpSym, 1);
			sym.push_back(tmpSym);
		}

		mName = "";
		for (int i = 1; i < iterator; i++) {

			mName.push_back(sym[i]);
		};

		fin.read((char*)&mId, 4);

			inputBinary* inputobject;

			switch (mId) {

			case 1:

				inputobject = new inputBinaryLine;
				inputobject->input(fin, arrOfPoints, options);
				delete inputobject;
				break;

			case 2:
				arrOfPoints.clear();
				options.clear();
				inputobject = new inputBinaryRectangle;
				inputobject->input(fin, arrOfPoints, options);
				delete inputobject;
				break;

			case 3:
				arrOfPoints.clear();
				options.clear();
				inputobject = new inputBinaryCircle;
				inputobject->input(fin, arrOfPoints, options);
				delete inputobject;
				break;

			case 4:
				arrOfPoints.clear();
				options.clear();
				inputobject = new inputBinaryPolyLine;
				inputobject->input(fin, arrOfPoints, options);
				delete inputobject;
				break;

			}
		
	}

private:

};




#endif

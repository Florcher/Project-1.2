#ifndef __FACTORYS_H_
#define __FACTORYS_H_

#include <iostream>
#include "Factorys.h"
#include <string>
#include "proekt.h"
#include <vector>

struct abstractFactory {

	virtual void create(std::istream& input, const std::string& name_, int id_, object** myObjects, const int iterator)
	{

	}
};


struct lineFactory : public abstractFactory {

	void create(std::istream& input, const std::string& name_, int id_, object** myObjects, const int iterator) override
	{
		vector2D start, end;
		input >> start;
		input >> end;

		myObjects[iterator] = new line(name_, id_, start, end);
	}

};


struct rectangleFactory : public abstractFactory {

	void create(std::istream& input, const std::string& name_, int id_, object** myObjects, const int iterator) override
	{
		vector2D leftDownPoint;
		double width, lenth;

		input >> leftDownPoint;
		input >> lenth;
		input >> width;

		myObjects[iterator] = new rectangle(name_, id_, leftDownPoint, lenth, width);
	}
};


struct circleFactory : public abstractFactory {

	void create(std::istream& input, const std::string& name_, int id_, object** myObjects, const int iterator) override
	{
		vector2D center;
		double radius;

		input >> center;
		input >> radius;

		myObjects[iterator] = new circle(name_, id_, center, radius);
	}
};


struct polylineFactory : public abstractFactory {

	void create(std::istream& input, const std::string& name_, int id_, object** myObjects, const int iterator) override
	{
		int countOfPoints;
		input >> countOfPoints;

		std::vector<vector2D> arrOfPoints(countOfPoints);

		for (int i = 0; i < countOfPoints; i++) {
			input >> arrOfPoints[i];
		}

		myObjects[iterator] = new polyline(name_, id_, arrOfPoints);
	}
};

#endif __FACTORYS_H_


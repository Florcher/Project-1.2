#ifndef __FACTORYS_H_
#define __FACTORYS_H_

#include <iostream>
#include "Factorys.h"
#include <string>
#include "proekt.h"
#include <vector>


struct Factory {
	virtual void create(std::istream& input, const std::string& name_, int id_, object** myObjects, const int iterator)
	{

	}

};


struct abstractFactory : public Factory {

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



struct abstructBinaryFactory : Factory {

};


struct lineBinaryFactory : public abstructBinaryFactory {

    void create(std::istream& input, const std::string& name_, const int id_, object** myObjects, const int iterator) override
	{
		vector2D start, end;

		input.read((char*)&start.x, 8);
		input.read((char*)&start.y, 8);
		input.read((char*)&end.x, 8);
		input.read((char*)&end.y, 8);

		myObjects[iterator] = new line(name_, id_, start, end);
	}

};


struct rectangleBinaryFactory : public abstructBinaryFactory {

	void create(std::istream& input, const std::string& name_, const int id_, object** myObjects, const int iterator) override
	{
		vector2D leftdownPoint;
		double lenth, width;

		input.read((char*)&leftdownPoint.x, 8);
		input.read((char*)&leftdownPoint.y, 8);
		input.read((char*)&lenth, sizeof(double));
		input.read((char*)&width, sizeof(double));

		myObjects[iterator] = new rectangle(name_, id_, leftdownPoint, lenth, width);
	}

};


struct circleBinaryFactory : public abstructBinaryFactory {

	void create(std::istream& input, const std::string& name_, const int id_, object** myObjects, const int iterator) override
	{
		vector2D center;
		double radius;

		input.read((char*)&center.x, 8);
		input.read((char*)&center.y, 8);
		input.read((char*)&radius, sizeof(double));

		myObjects[iterator] = new circle(name_, id_, center, radius);
	}

};


struct polylinBinaryFactory : public abstructBinaryFactory {

	void create(std::istream& input, const std::string& name_, const int id_, object** myObjects, const int iterator) override
	{
		int countOfPoints;
		input.read((char*)&countOfPoints, 4);

		std::vector<vector2D> arrOfPoints(countOfPoints);

		for (int i = 0; i < countOfPoints; i++) {
			input.read((char*)&arrOfPoints[i].x, 8);
			input.read((char*)&arrOfPoints[i].y, 8);
		}

		myObjects[iterator] = new polyline(name_, id_, arrOfPoints);
	}

};


#endif __FACTORYS_H_


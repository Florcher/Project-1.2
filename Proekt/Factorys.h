#ifndef __FACTORYS_H_
#define __FACTORYS_H_

#include <iostream>
#include "Factorys.h"
#include <string>
#include "proekt.h"
#include <vector>
#include "inputChoice.h"
#include "inputObject.h"

struct Factory {
	virtual void create(inputCHOICE& inputobject, object** myObjects, const int iterator)
	{

	}

};


struct abstractFactory : public Factory {

};


struct lineFactory : public abstractFactory {

	void create(inputCHOICE& inputobject, object** myObjects, const int iterator) override
	{
		std::string name = inputobject.getName();
		int id = inputobject.getId();
		vector2D start = inputobject.getArrOfPoints()[0];
		vector2D end = inputobject.getArrOfPoints()[1];

		myObjects[iterator] = new line(name, id, start, end);
	}

};


struct rectangleFactory : public abstractFactory {

	void create(inputCHOICE& inputobject, object** myObjects, const int iterator) override
	{
		std::string name = inputobject.getName();
		int id = inputobject.getId();
		vector2D leftDownPoint = inputobject.getArrOfPoints()[0];
		double lenth = inputobject.getOptions()[0];
		double width = inputobject.getOptions()[1];

		myObjects[iterator] = new rectangle(name, id, leftDownPoint, lenth, width);
	}
};


struct circleFactory : public abstractFactory {

	void create(inputCHOICE& inputobject, object** myObjects, const int iterator) override
	{
		std::string name = inputobject.getName();
		int id = inputobject.getId();
		vector2D center = inputobject.getArrOfPoints()[0];
		double radius = inputobject.getOptions()[0];

		myObjects[iterator] = new circle(name, id, center, radius);
	}
};


struct polylineFactory : public abstractFactory {

	void create(inputCHOICE& inputobject, object** myObjects, const int iterator) override
	{
		std::string name = inputobject.getName();
		int id = inputobject.getId();

		myObjects[iterator] = new polyline(name, id, inputobject.getArrOfPoints());
	}
};





//struct abstructBinaryFactory{
//	virtual void create(std::istream& input, const std::string& name_, int id_, object** myObjects, const int iterator)
//	{
//
//	}
//
//};
//
//
//struct lineBinaryFactory : public abstructBinaryFactory {
//
//    void create(std::istream& input, const std::string& name_, const int id_, object** myObjects, const int iterator) override
//	{
//
//
//
//		myObjects[iterator] = new line(name_, id_, start, end);
//	}
//
//};
//
//
//struct rectangleBinaryFactory : public abstructBinaryFactory {
//
//	void create(std::istream& input, const std::string& name_, const int id_, object** myObjects, const int iterator) override
//	{
//
//		myObjects[iterator] = new rectangle(name_, id_, leftdownPoint, lenth, width);
//	}
//
//};
//
//
//struct circleBinaryFactory : public abstructBinaryFactory {
//
//	void create(std::istream& input, const std::string& name_, const int id_, object** myObjects, const int iterator) override
//	{
//		myObjects[iterator] = new circle(name_, id_, center, radius);
//	}
//
//};
//
//
//struct polylinBinaryFactory : public abstructBinaryFactory {
//
//	void create(std::istream& input, const std::string& name_, const int id_, object** myObjects, const int iterator) override
//	{
//	
//
//		myObjects[iterator] = new polyline(name_, id_, arrOfPoints);
//	}
//
//};


#endif __FACTORYS_H_


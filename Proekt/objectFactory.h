
#ifndef __OBJECTFACTORY_H_
#define __OBJECTFACTORY_H_

#include <iostream>
#include <vector>
#include "proekt.h"
#include "Factorys.h"
#include "inputChoice.h"
#include "inputObject.h"

class objectFactory {

public:

	void createObject(buffer& inputobject, object** myObjects, const int iterator) {

		factory* factory;

		switch (inputobject.getId()) 
		{
		case 1:

			factory = new lineFactory;
			factory->create(inputobject, myObjects, iterator);
			delete factory;
			break;

		case 2:

			factory = new rectangleFactory;
			factory->create(inputobject, myObjects, iterator);
			delete factory;
			break;

		case 3:

			factory = new circleFactory;
			factory->create(inputobject, myObjects, iterator);
			delete factory;
			break;

		case 4:

			factory = new polylineFactory;
			factory->create(inputobject, myObjects, iterator);
			delete factory;
			break;

		default:
			break;
		}

		
	}


private:

};



//class objectBinaryFactory {
//
//
//public:
//
//	void createObject(std::istream& input, const std::string& name_, int id_, object** myObjects, const int iterator) {
//
//		abstructBinaryFactory* binaryFactory;
//
//		switch (id_)
//		{
//		case 1:
//
//			binaryFactory = new lineBinaryFactory;
//			binaryFactory->create(input, name_, id_, myObjects, iterator);
//			delete binaryFactory;
//			break;
//
//		case 2:
//
//			binaryFactory = new rectangleBinaryFactory;
//			binaryFactory->create(input, name_, id_, myObjects, iterator);
//			delete binaryFactory;
//			break;
//
//		case 3:
//
//			binaryFactory = new circleBinaryFactory;
//			binaryFactory->create(input, name_, id_, myObjects, iterator);
//			delete binaryFactory;
//			break;
//
//		case 4:
//
//			binaryFactory = new polylinBinaryFactory;
//			binaryFactory->create(input, name_, id_, myObjects, iterator);
//			delete binaryFactory;
//			break;
//
//		default:
//			break;
//		}
//
//
//	}
//
//
//private:
//
//};

#endif __OBJECTFACTORY_H_
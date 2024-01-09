
#ifndef __OBJECTFACTORY_H_
#define __OBJECTFACTORY_H_

#include <iostream>
#include <vector>
#include "proekt.h"
#include "Factorys.h"

class objectFactory {

public:

	void createObject(std::istream& input, const std::string& name_, int id_, object** myObjects, const int iterator) {

		abstractFactory* factory;

		switch (id_) 
		{
		case 1:

			factory = new lineFactory;
			factory->create(input, name_, id_, myObjects, iterator);
			delete factory;
			break;

		case 2:

			factory = new rectangleFactory;
			factory->create(input, name_, id_, myObjects, iterator);
			delete factory;
			break;

		case 3:

			factory = new circleFactory;
			factory->create(input, name_, id_, myObjects, iterator);
			delete factory;
			break;

		case 4:

			factory = new polylineFactory;
			factory->create(input, name_, id_, myObjects, iterator);
			delete factory;
			break;

		default:
			break;
		}

		
	}


private:

};

#endif __OBJECTFACTORY_H_

#ifndef __OBJECTFACTORY_H_
#define __OBJECTFACTORY_H_

#include <iostream>
#include <vector>
#include "proekt.h"
#include "Factorys.h"
#include <map>



class objectFactory {
public:

	objectFactory() {
		addType(1, new lineCreator);
		addType(2, new rectangCreator);
		addType(3, new circleCreator);
		addType(4, new polylineCreator);
	}

	object* createObject(int id) {

		auto it = mTypes.at(id);
		return it->create();
	}

	void addType(int id, Creator* object) {
		mTypes.emplace(id, object);
	}

	void removeType(const int id) {
		mTypes.erase(id);
	}

	std::map<int, Creator*> mTypes;
};

#endif __OBJECTFACTORY_H_
#ifndef __FACTORYS_H_
#define __FACTORYS_H_

#include <iostream>
#include "Factorys.h"
#include <string>
#include "proekt.h"
#include <vector>

struct Creator {
	virtual object* create() = 0
	{

	}

};

struct lineCreator : public Creator {

	object* create() override 
	{
		return new Line;
	}

};


struct rectangCreator : public Creator {

	object* create() override
	{
		return new Rectangle;
	}
};


struct circleCreator : public Creator {

    object* create() override
	{
		return new Circle;
	}
};


struct polylineCreator : public Creator {

	object* create() override
	{
		return new Polyline;
	}
};


#endif __FACTORYS_H_


#pragma once
#include <iostream>
#include <vector>
#include "proekt.h"


class objectFactory {

public:

	void createObject(std::istream& input, const std::string& name_, int id_, object** myObjects, const int iterator) {


		if (id_ == 1) {

			vector2D start, end;
			input >> start;
			input >> end;

			myObjects[iterator] = new line(name_, id_, start, end);
		}
		else {

			if (id_ == 2) {
				vector2D leftDownPoint;
				double width, lenth;

				input >> leftDownPoint;
				input >> lenth;
				input >> width;

				myObjects[iterator] = new rectangle(name_, id_, leftDownPoint, lenth, width);
			}
			else {

				if (id_ == 3) {
					vector2D center;
					double radius;

					input >> center;
					input >> radius;

					myObjects[iterator] = new circle(name_, id_, center, radius);
				}

			}
		}
	}


private:

};
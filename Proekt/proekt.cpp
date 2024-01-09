#include "proekt.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>


std::ostream& operator<< (std::ostream& output, const vector2D& vector2D) {

	output << "(" << vector2D.x << ", " << vector2D.y << ")" << std::endl;

	return output;
}
 std::istream& operator>> (std::istream& input, vector2D& vector2D) {

	 input >> vector2D.x;
	 input >> vector2D.y;

	 return input;
}

vector2D& vector2D::operator+(const vector2D& rhs) {

	vector2D tmpVector = *this;
	tmpVector.x = tmpVector.x + rhs.x;
	tmpVector.y = tmpVector.y + rhs.y;

	return tmpVector;

}

vector2D& vector2D::operator-(const vector2D& rhs) {

	vector2D tmpVector = *this;
	tmpVector.x = tmpVector.x - rhs.x;
	tmpVector.y = tmpVector.y - rhs.y;

	return tmpVector;

}

const vector2D& vector2D::operator=(const vector2D& rhs) {

	if (this != &rhs) {
		this->x = rhs.x;
		this->y = rhs.y;

		return *this;
	}

	return *this;
}


line::line() {
	
}

line::line(const std::string& name_, const int id_, const vector2D& start_, const vector2D& end_) 
	: object(name_, id_), mStart(start_), mEnd(end_){

}

double line::getModul() const {

	vector2D dir;

	dir.x = mEnd.x - mStart.x;
	dir.y = mEnd.y - mStart.y;

	return sqrt(dir.x * dir.x + dir.y * dir.y);
}

line::line(const line& rhs) {

	this->setName(rhs.getName());
	this->setIndex(rhs.getindex());
	this->mStart = rhs.getStart();
	this->mEnd = rhs.getEnd();
	
}
const line& line::operator= (const line& rhs) {

	if (this != &rhs) {

		this->setName(rhs.getName());
		this->setIndex(rhs.getindex());
		this->mStart = rhs.getStart();
		this->mEnd = rhs.getEnd();

		return *this;
	}

	return *this;
}

void line::print() const {

	object::print();

	vector2D dir;

	dir.x = mEnd.x - mStart.x;
	dir.y = mEnd.y - mStart.y;

	std::cout << dir;
}


rectangle::rectangle(const std::string& name_,const int id_, const vector2D& vector2D, const double lenth_, const double width_) 
	: object(name_, id_), mLeftDownPoint(vector2D), mLenth(lenth_), mWidth(width_) 
{
	/*Point tochkitmp[4] = { a, b, c, d };

	uporyadochenie(tochkitmp);
	set_Koordinati_Vectorov();
	Area();
	Perimetr();*/
}

//void Rectangle::uporyadochenie(const Point arr[]) {
//
//	int iterator = 0;
//
//	double xmin = arr[0].x;
//	double ymin = arr[0].y;
//	for (int i = 1; i < 4; i++) {
//		if (arr[i].x < xmin && arr[i].y < ymin) {
//			iterator = i;
//		}
//	}
//
//	tochki[0].x = arr[iterator].x;
//	tochki[0].y = arr[iterator].y;
//
//	for (int i = 0; i < 4; i++) {
//		if (arr[i].x == tochki[0].x && arr[i].y > tochki[0].y) {
//			iterator = i;
//		}
//	}
//
//	tochki[1].x = arr[iterator].x;
//	tochki[1].y = arr[iterator].y;
//
//	for (int i = 0; i < 4; i++) {
//		if ((arr[i].x != tochki[0].x) && (arr[i].y != tochki[0].y)) {
//			iterator = i;
//		}
//	}
//
//	tochki[2].x = arr[iterator].x;
//	tochki[2].y = arr[iterator].y;
//
//	for (int i = 0; i < 4; i++) {
//		if (arr[i].y == tochki[0].y && arr[i].x > tochki[0].x) {
//			iterator = i;
//		}
//	}
//
//	tochki[3].x = arr[iterator].x;
//	tochki[3].y = arr[iterator].y;
//
//}

//void Rectangle::set_Koordinati_Vectorov() {
//
//	Line line_of_storoni[4];
//	Line AB{ "AB", 1, tochki[0], tochki[1] };
//	Line BC{ "BC", 2, tochki[1], tochki[2] };
//	Line CD{ "CD", 3, tochki[2], tochki[3] };
//	Line DA{ "DA", 4, tochki[3], tochki[0] };
//
//	line_of_storoni[0] = AB;
//	line_of_storoni[1] = BC;
//	line_of_storoni[2] = CD;
//	line_of_storoni[3] = DA;
//
//	for (int i = 0; i < 4; i++) {
//		koordinatyVectorov[i].x = line_of_storoni[i].getKoordinataX();
//		koordinatyVectorov[i].y = line_of_storoni[i].getKoordinataY();
//	}
//
//}

void rectangle::print() const {

	object::print();

	std::cout << "left down point: " << mLeftDownPoint;
	std::cout << "lenth = " << mLenth << std::endl;
	std::cout << "width = " << mWidth << std::endl;
	std::cout << "perimetr = " << getPerimetr() << std::endl;
	std::cout << "area = " << getArea() << std::endl;
	

}


circle::circle(const std::string& name_, const int id_, const vector2D& center_, const double radius_) 
	: object(name_, id_), mCenter(center_), mRadius(radius_) {

}

void circle::print() const {

	std::vector<vector2D> arrOfPoints;

	const double Pi = 3.141592653589793;

	vector2D tmpPoint;

	for (int i = 0; i < 360; i++) {

		tmpPoint.x = mCenter.x + mRadius * cos(i * Pi / 180);
		tmpPoint.y = mCenter.y + mRadius * sin(i * Pi / 180);

		arrOfPoints.push_back(tmpPoint);
	}

	std::vector<line> arrOfvector;

	line tmpVector;

	for (int i = 0; i < 359; i++) {

		tmpVector.setName("vector");
		tmpVector.setIndex(i);
		tmpVector.setStart(arrOfPoints[i]);
		tmpVector.setEnd(arrOfPoints[i + 1]);

		arrOfvector.push_back(tmpVector);
	}

	object::print();

	std::cout << "Center = " << mCenter;
	std::cout << "radius = " << mRadius << std::endl;

	for (int i = 0; i < arrOfPoints.size() - 1; i++) {
		arrOfvector[i].print();
	}

}
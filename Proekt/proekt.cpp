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

}

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
	std::cout << "area = " << getArea() << std::endl;

	for (int i = 0; i < arrOfPoints.size() - 1; i++) {
		arrOfvector[i].print();
	}

}

polyline::polyline() {

}

polyline::polyline(const std::string& name_, const int id_, std::vector<vector2D> arrOfPoints_)
	: object(name_, id_) 
{
	for (int i = 0; i < arrOfPoints_.size(); i++)
		Points.push_back(arrOfPoints_[i]);
}

void polyline::print() const {

	object::print();

	std::cout << "count of points " << Points.size() << std::endl;

	std::vector<line> arrOfVectors;
	line tmpVector;

	for (int i = 0; i < Points.size() - 1; i++) {

		tmpVector.setName("vector");
		tmpVector.setIndex(i);
		tmpVector.setStart(Points[i]);
		tmpVector.setEnd(Points[i + 1]);

		arrOfVectors.push_back(tmpVector);
	}

	for (int i = 0; i < arrOfVectors.size(); i++) {
		arrOfVectors[i].print();
	}

}
#pragma once
#include <iostream>
#include <string>

struct vector2D {

	friend std::ostream& operator<< (std::ostream&, const vector2D&);
	friend std::istream& operator>> (std::istream&, vector2D&);

	const vector2D& operator=(const vector2D&);
	vector2D& operator+(const vector2D&);
	vector2D& operator-(const vector2D&);

	double x = 0;
	double y = 0;
};


class object {

public:

	object() {};
	object(const std::string& name_, const int id_) { mName = name_; id = id_; };
	virtual ~object() {};

	virtual void print() const { std::cout << mName << std::endl << id << std::endl; };

	void setName(const std::string& name_) { mName = name_; };
	void setIndex(const int id_) { id = id_; };

    std::string getName() const { return mName; };
	int getindex() const { return id; };

private:

	std::string mName;
	int id;
};


class line : public object{

public:

	line();
    line(const std::string&, const int, const vector2D&, const vector2D&);
	line(const line&);
	const line& operator=(const line&);
	~line() {};

	void setStart(const vector2D& start) { this->mStart = start; };
	void setEnd(const vector2D& end) { this->mEnd = end; };

	vector2D getStart() const { return mStart; };
	vector2D getEnd() const { return mEnd; };

	double getModul() const;

	void print() const override;

private:

	vector2D mStart, mEnd;
};


class rectangle : public object {

public:

	rectangle() {};
	rectangle(const std::string&, const int, const vector2D&, const double, const double);
	~rectangle() {};


	void setLeftDownPoint(const vector2D& vector2D) { mLeftDownPoint = vector2D; };
	void setLenth(const int& lenth_) { mLenth = lenth_; };
	void setWidth(const int& width_) { mWidth = width_; };

	vector2D getLeftDownPoint() { return mLeftDownPoint; };
	double getLenth() { return mLenth; };
	double getWidth() { return mWidth; };

	double getArea() const { return mLenth * mWidth; };
	double getPerimetr() const { return 2 * mLenth + 2 * mWidth; };

	void print() const override;

private:

	vector2D mLeftDownPoint;

	double mLenth, mWidth;
};


class circle : public object {

public:

	circle() {};
	circle(const std::string&, const int, const vector2D&, const double);

	void setCenter(const vector2D& center_) { mCenter = center_; };
	void setRadius(const double radius_) { mRadius = radius_; };

	vector2D getCenter() const { return mCenter; };
	double getRadius() const { return mRadius; };

	double getArea() const { return 3.141592653589793 * mRadius * mRadius; };

	void print() const override;

private:

	vector2D mCenter;
	double mRadius;
};
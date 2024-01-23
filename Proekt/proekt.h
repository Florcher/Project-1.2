
#ifndef __PROEKT_H_
#define __PROEKT_H_

#include <iostream>
#include <string>
#include <vector>

struct vector2D {

	friend std::ostream& operator<< (std::ostream&, const vector2D&);
	friend std::istream& operator>> (std::istream&, vector2D&);

	vector2D operator+(const vector2D&);
	vector2D operator-(const vector2D&);

	double x = 0;
	double y = 0;
};


class object {
public:

	object() = default;
	object(const std::string& name, const int id);
	virtual ~object() {};

	virtual void binaryInput(std::istream& input);
	virtual void input(std::istream& input);
	virtual void print();

	void setName(const std::string& name);
	void setId(const int id);

    std::string getName() const;
	int getindex() const;

private:

	std::string mName;
	int mId;
};


class Line : public object{
public:

	Line() = default;
    Line(const std::string& name, const int id, const vector2D& stat, const vector2D& end);
	~Line() {};

	void setStart(const vector2D& start);
	void setEnd(const vector2D& end);

	vector2D getStart() const;
	vector2D getEnd() const ;

	double getLenth();

	void binaryInput(std::istream& input) override;
	void input(std::istream& input) override;
	void print() override;

private:

	vector2D mStart, mEnd;
};


class Rectangle : public object {

public:

	Rectangle() = default;
	Rectangle(const std::string& name, const int id, const vector2D& leftDownPoint, const double lenth, const double width);
	~Rectangle() {};


	void setLeftDownPoint(const vector2D& vector2D);
	void setLenth(const int& lenth_);
	void setWidth(const int& width_);

	vector2D getLeftDownPoint();
	double getLenth();
	double getWidth();

	double getArea() const;
	double getPerimetr() const;

	void binaryInput(std::istream& input) override;
	void input(std::istream& input) override;
	void print() override;

private:

	vector2D mLeftDownPoint;

	double mLenth, mWidth;
};


class Circle : public object {
public:

	Circle() = default;
	Circle(const std::string& name, const int id, const vector2D& center, const double radius);

	void setCenter(const vector2D& center_);
	void setRadius(const double radius_);

	vector2D getCenter() const;
	double getRadius() const;

	double getArea() const;
	 
	void binaryInput(std::istream& input) override;
	void input(std::istream& input) override;
	void print() override;

private:

	vector2D mCenter;
	double mRadius;
	std::vector<Line> createLines();
};

class Polyline : public object {
public:

	Polyline() = default;
	Polyline(const std::string& name, const int id, const std::vector<vector2D>& points);
  	
	void binaryInput(std::istream& input) override;
	void input(std::istream& input) override;
	void print() override;

private:

	std::vector<vector2D> mPoints;
	void createLines(std::vector<Line>& lines);
};

#endif __PROEKT_H_
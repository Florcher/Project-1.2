#ifndef __INPUTBEHAVIOR_H_
#define __INPUTBEHAVIOR_H_
#include <iostream>
#include <string>
#include <vector>
#include "proekt.h"


//struct inputBinaryLine : public inputBinary {
//
//	void input(std::istream& input, std::vector<vector2D>& arrOfPoints, std::vector<double>& options) override
//	{
//		vector2D start, end;
//
//		input.read((char*)&start.x, 8);
//		input.read((char*)&start.y, 8);
//		input.read((char*)&end.x, 8);
//		input.read((char*)&end.y, 8);
//
//		arrOfPoints.push_back(start);
//		arrOfPoints.push_back(end);
//	}
//};
//
//struct inputBinaryRectangle : public inputBinary {
//
//	void input(std::istream& input, std::vector<vector2D>& arrOfPoints, std::vector<double>& options) override
//	{
//		vector2D leftdownPoint;
//		double lenth, width;
//
//		input.read((char*)&leftdownPoint.x, 8);
//		input.read((char*)&leftdownPoint.y, 8);
//		input.read((char*)&lenth, 8);
//		input.read((char*)&width, 8);
//
//		arrOfPoints.push_back(leftdownPoint);
//		options.push_back(lenth);
//		options.push_back(width);
//	}
//};
//
//struct inputBinaryCircle : public inputBinary {
//
//	void input(std::istream& input, std::vector<vector2D>& arrOfPoints, std::vector<double>& options) override
//	{
//		vector2D center;
//		double radius;
//
//		input.read((char*)&center.x, 8);
//		input.read((char*)&center.y, 8);
//		input.read((char*)&radius, 8);
//
//		arrOfPoints.push_back(center);
//		options.push_back(radius);
//	}
//};
//
//struct inputBinaryPolyLine : public inputBinary {
//
//	void input(std::istream& input, std::vector<vector2D>& arrOfPoints, std::vector<double>& options) override
//	{
//		int countOfPoints;
//		input.read((char*)&countOfPoints, 4);
//
//		
//
//		for (int i = 0; i < countOfPoints; i++) {
//			vector2D point;
//
//			input.read((char*)&point.x, 8);
//			input.read((char*)&point.y, 8);
//
//			arrOfPoints.push_back(point);
//
//		}
//	}
//};








#endif

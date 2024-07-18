#pragma once

#include <Shape.hpp>

class Rectangle: public Shape{
private:
	double	_x1, _y1, _x2, _y2, _x3, _y3, _x4, _y4;
public:
	Rectangle(void);
	Rectangle(
		double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4
	);
	~Rectangle();

	double	getArea(void);
	double	getPerimeter(void);
};

Rectangle::Rectangle(void):
_x1(0.f), _y1(0.f), _x2(0.f), _y2(0.f), _x3(0.f), _y3(0.f), _x4(0.f), _y4(0.f){
}

Rectangle::Rectangle(
	double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4
): _x1(x1), _y1(y1), _x2(x2), _y2(y2), _x3(x3), _y3(y3), _x4(x4), _y4(y4){
}

Rectangle::~Rectangle(){
}

double	Rectangle::getArea(void){
	return (findDist(_x1, _y1, _x2, _y2) * findDist(_x1, _y1, _x3, _y3));
}

double	Rectangle::getPerimeter(void){
	return (findDist(_x1, _y1, _x2, _y2) + findDist(_x1, _y1, _x3, _y3) +
			findDist(_x4, _y4, _x2, _y2) + findDist(_x4, _y4, _x3, _y3));
}

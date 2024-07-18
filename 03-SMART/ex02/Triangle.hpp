#pragma once

#include <Shape.hpp>

class Triangle: public Shape{
private:
	double	_x1, _y1, _x2, _y2, _x3, _y3;
public:
	Triangle(void);
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
	~Triangle();

	double	getArea(void);
	double	getPerimeter(void);
};

Triangle::Triangle(void): _x1(0.f), _y1(0.f), _x2(0.f), _y2(0.f), _x3(0.f), _y3(0.f){
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3):
_x1(x1), _y1(y1), _x2(x2), _y2(y2), _x3(x3), _y3(y3){
}

Triangle::~Triangle(){
}

double	Triangle::getArea(void){
	double	a = findDist(_x1, _y1, _x2, _y2);
	double	b = findDist(_x2, _y2, _x3, _y3);
	double	c = findDist(_x3, _y3, _x1, _y1);
	double	s = (a + b + c) / 2;  
	return (sqrt(s * (s - a) * (s - b) * (s - c)));
}

double	Triangle::getPerimeter(void){
	return (findDist(_x1, _y1, _x2, _y2) + findDist(_x2, _y2, _x3, _y3) +
			findDist(_x3, _y3, _x1, _y1));
}

#pragma once

#include <Shape.hpp>

class Triangle: public Shape{
private:
	double	_x1, _y1, _x2, _y2, _x3, _y3;
public:
	Triangle(void);
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
	~Triangle();

	double	calculatingArea(void);
	double	calculatingPerimeter(void);
};

Triangle::Triangle(void): _x1(0.f), _y1(0.f), _x2(0.f), _y2(0.f), _x3(0.f), _y3(0.f){
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3):
_x1(x1), _y1(y1), _x2(x2), _y2(y2), _x3(x3), _y3(y3){
}

Triangle::~Triangle(){
}

double	Triangle::calculatingArea(void){
	double	a = find_dist(_x1, _y1, _x2, _y2);
	double	b = find_dist(_x2, _y2, _x3, _y3);
	double	c = find_dist(_x3, _y3, _x1, _y1);
	double	s = (a + b + c) / 2;  
	return (sqrt(s * (s - a) * (s - b) * (s - c)));
}

double	Triangle::calculatingPerimeter(void){
	return (find_dist(_x1, _y1, _x2, _y2) + find_dist(_x2, _y2, _x3, _y3) +
			find_dist(_x3, _y3, _x1, _y1));
}

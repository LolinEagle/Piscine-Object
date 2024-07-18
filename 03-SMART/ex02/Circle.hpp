#pragma once

#include <Shape.hpp>

class Circle: public Shape{
private:
	double	_radius;
public:
	Circle(void);
	Circle(double radius);
	~Circle();

	double	getArea(void);
	double	getPerimeter(void);
};

Circle::Circle(void): _radius(0.f){
}

Circle::Circle(double radius): _radius(radius){
}

Circle::~Circle(){
}

double	Circle::getArea(void){
	return (_radius * M_PI);
}

double	Circle::getPerimeter(void){
	return (_radius * M_PI * 2);
}

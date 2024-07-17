#pragma once

#include <Shape.hpp>

class Circle: public Shape{
private:
	double	_radius;
public:
	Circle(void);
	Circle(double radius);
	~Circle();

	double	calculatingArea(void);
	double	calculatingPerimeter(void);
};

Circle::Circle(void): _radius(0.f){
}

Circle::Circle(double radius): _radius(radius){
}

Circle::~Circle(){
}

double	Circle::calculatingArea(void){
	return (_radius * M_PI);
}

double	Circle::calculatingPerimeter(void){
	return (_radius * M_PI * 2);
}

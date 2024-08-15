#pragma once

#include <header.hpp>
#include <City.hpp>

class City;

class Rail{
private:
	City*	_pointA;
	City*	_pointB;
	float	_maxSpeed;
	float	_length;
public:
	Rail(float maxSpeed, float length):
	_pointA(NULL), _pointB(NULL), _maxSpeed(maxSpeed), _length(length){}
	Rail(float maxSpeed, float length, City* pointA, City* pointB):
	_pointA(pointA), _pointB(pointB), _maxSpeed(maxSpeed), _length(length){}
	~Rail(){}

	City*	getPoint(char c);
	float	getMaxSpeed(void){return (_maxSpeed);};
	float	getLength(void){return (_length);};
	void	setPoint(City* point);

	void	event(Event e);
	City*	getOtherPoint(City* point);
};

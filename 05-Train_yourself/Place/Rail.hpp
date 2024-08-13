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
	~Rail(){}

	City*	getPoint(char c);
	void	setPoint(City* point);
};

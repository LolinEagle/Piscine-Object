#pragma once

#include <header.hpp>
#include <City.hpp>

class City;

class Rail{
private:
	City*		_pointA;
	City*		_pointB;
	uint32_t	_maxSpeed;
public:
	Rail(uint32_t maxSpeed): _pointA(NULL), _pointB(NULL), _maxSpeed(maxSpeed){}
	~Rail(){}

	City*	getPoint(char c);
	void	setPoint(City* point);
};

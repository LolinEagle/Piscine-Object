#pragma once

#include <City.hpp>

class Train{
private:
	string		_name;
	uint32_t	_id;
	uint32_t	_maxAcceleration;
	uint32_t	_maxBrake;
	City*		_position;
public:
	Train(string name, uint32_t maxAcceleration, uint32_t maxBrake);
	~Train(){}

	void	setPosition(City* position){_position = position;}

	uint32_t	pathfinding(City* city);
};

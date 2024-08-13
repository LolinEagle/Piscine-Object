#pragma once

#include <City.hpp>

class Train{
private:
	string		_name;
	uint32_t	_id;
	float		_maxAcceleration, _maxBrake;
	City*		_departure;
	City*		_arrival;
	string		_departureHour;
public:
	Train(string name, float maxAcceleration, float maxBrake, City* departure,
	City* arrival, string departureHour);
	~Train(){}

	float	pathfinding(void);
	void	printAll(void);
};

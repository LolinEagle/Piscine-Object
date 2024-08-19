#pragma once

#include <City.hpp>

class Train{
private:
	string	_name;
	uint	_id;
	float	_maxAcceleration, _maxBrake;
	City*	_departure;
	City*	_arrival;
	string	_departureHour;
public:
	Train(string name, float maxAcceleration, float maxBrake, City* departure,
	City* arrival, string departureHour);
	~Train(){}

	string	getName(void){return (_name);}

	void	pathfindingRecursive(uint recursive, vector<City*> nodes, City* pos);
	void	pathfinding(void);
	void	printAll(void);
};

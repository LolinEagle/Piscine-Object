#pragma once

#include <City.hpp>

class Train{
private:
	string	_name;
	uint	_id;
	float	_maxAcceleration, _maxBrake, _departureHour;
	City*	_departure;
	City*	_arrival;

	vector<City*>	_nodes;
	float			_time;
public:
	Train(string name, float maxAcceleration, float maxBrake, float departureHour,
	City* departure, City* arrival);
	~Train(){}

	string	getName(void){return (_name);}

	void	pathfindingRecursive(uint recursive, vector<City*> nodes, City* pos);
	void	pathfinding(void);
	void	printAll(void);
};

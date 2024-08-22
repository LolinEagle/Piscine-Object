#pragma once

#include <City.hpp>

class Train{
private:
	enum State{
		SpeedingUp,
		MaintainingSpeed,
		Bracking,
		Stopped,
	};

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

	string			getName(void){return (_name);}
	float			getMaxAcceleration(void){return (_maxAcceleration);}
	float			getMaxBrake(void){return (_maxBrake);}
	vector<City*>	getNodes(void){return (_nodes);}
	float			getTime(void){return (_time);}

	void	pathfindingRecursive(uint recursive, vector<City*> nodes, City* pos);
	void	pathfinding(void);
	void	output(float t, State& state, size_t i, float d);
	void	execute(void);
	void	printAll(void);
};

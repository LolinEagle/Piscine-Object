#pragma once

#include <City.hpp>
#include <Overtaking.hpp>

class Overtaking;

class Train{
private:
	enum State{
		SpeedingUp,
		MaintainingSpeed,
		Bracking,
		Stopped,
		PassengerDiscomfort,
	};

	string	_name;
	uint	_id;
	float	_maxAcceleration, _maxBrake, _departureHour;
	City*	_departure;
	City*	_arrival;

	vector<City*>	_nodes;
	float			_time;
	Overtaking*		_overtaking;

	void	pathfindingRecursive(uint recursive, vector<City*> nodes, City* pos);
	float	getMinute(float hour);
	void	outputFile(float hour, State& state, size_t i, float d);
	void	output(float t, State& state, size_t i, float d);
public:
	Train(string name, float maxAcceleration, float maxBrake, float departureHour,
	City* departure, City* arrival, Overtaking* overtaking);
	~Train(){}

	string			getName(void){return (_name);}
	float			getMaxAcceleration(void){return (_maxAcceleration);}
	float			getMaxBrake(void){return (_maxBrake);}
	vector<City*>	getNodes(void){return (_nodes);}
	float			getTime(void){return (_time);}

	// Command
	void	pathfinding(void);
	void	execute(void);
	void	printAll(void);
};

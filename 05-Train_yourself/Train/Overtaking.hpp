#pragma once

#include <Train.hpp>

class Overtaking{
private:
	vector<Train*>	_trains;
public:
	Overtaking(void){}
	~Overtaking(){}

	vector<Train*>	getTrains(void){return (_trains);}

	void	addTrain(Train* train);
};

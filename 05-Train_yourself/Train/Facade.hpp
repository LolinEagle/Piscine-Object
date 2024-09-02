#pragma once

#include <City.hpp>
#include <Overtaking.hpp>
#include <Train.hpp>

class Facade{
private:
	Overtaking*	_overtaking;
	bool		_a, _b, _c;

	void	outputTrain(Train* train);
public:
	Facade(const string &railNetwork, const string &trainComposition);
	~Facade();

	void	output(void);
};

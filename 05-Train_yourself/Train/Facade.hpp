#pragma once

#include <City.hpp>
#include <Overtaking.hpp>
#include <Train.hpp>

class Facade{
private:
	Overtaking*	_overtaking;
	Train*		_ab1;
	Train*		_ac1;
	Train*		_ab2;
	bool		_a, _b, _c;

	void	outputTrain(Train* train);
public:
	Facade(const string &railNetwork, const string &trainComposition);
	~Facade();

	void	output(void);
};

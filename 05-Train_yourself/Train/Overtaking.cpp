#include <Overtaking.hpp>

Overtaking::~Overtaking(){
	for (City* city: _citys)
		delete (city);
	for (Train* train: _trains)
		delete (train);
}

City*	Overtaking::getCity(string name){
	for (City* city: _citys)
		if (city->getName() == name) return (city);
	return (NULL);
}

void	Overtaking::addCity(City* city){
	if (find(_citys.begin(), _citys.end(), city) == _citys.end())
		_citys.push_back(city);
}

void	Overtaking::addTrain(Train* train){
	if (find(_trains.begin(), _trains.end(), train) == _trains.end())
		_trains.push_back(train);
}

#include <Facade.hpp>

void	Facade::outputTrain(Train* train){
	cout << MAGENTA << setfill('_') << setw(109) << ENDL;
	train->pathfinding();
	train->execute();
}

Facade::Facade(const string &railNetwork, const string &trainComposition):
_a(true), _b(true), _c(true){
	_overtaking = Overtaking::getInstance();

	// Input
	_overtaking->inputRailNetwork(railNetwork);
	_overtaking->inputTrainComposition(trainComposition);
}

Facade::~Facade(){
	delete (_overtaking);
}

void	Facade::output(void){
	for (auto e: _overtaking->getEvents()){
		if (e.event == 0 && e.where->getName() == "CityA" && rand() % 100 < e.chance * 100)
			_a = false;
		else if (e.event == 0 && e.where->getName() == "CityB" && rand() % 100 < e.chance * 100)
			_b = false;
		else if (e.event == 0 && e.where->getName() == "CityC" && rand() % 100 < e.chance * 100)
			_c = false;
	}
	for (Train* train: _overtaking->getTrains()){
		if ((train->getName().find('A') != string::npos && _a == false) ||
			(train->getName().find('B') != string::npos && _b == false) ||
			(train->getName().find('C') != string::npos && _c == false))
			continue ;
		outputTrain(train);
	}
}

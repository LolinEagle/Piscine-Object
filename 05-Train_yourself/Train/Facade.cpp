#include <Facade.hpp>

void	Facade::outputTrain(Train* train){
	cout << MAGENTA << "------------------------------------------------------------------" << ENDL;
	train->pathfinding();
	train->execute();
}

Facade::Facade(const string &railNetwork, const string &trainComposition):
_a(true), _b(true), _c(true){
	_overtaking = Overtaking::getInstance();

	// Input
	_overtaking->inputRailNetwork(railNetwork);
	_overtaking->inputTrainComposition(trainComposition);

	// Set train
	_ab1 = _overtaking->getTrain("TrainAB1");
	_ac1 = _overtaking->getTrain("TrainAC");
	_ab2 = _overtaking->getTrain("TrainAB2");
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
	if (_a && _b) outputTrain(_ab1);
	if (_a && _c) outputTrain(_ac1);
	if (_a && _b) outputTrain(_ab2);
}

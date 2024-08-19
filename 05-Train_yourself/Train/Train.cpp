#include <Train.hpp>

Train::Train(string name, float maxAcceleration, float maxBrake, City* departure,
City* arrival, string departureHour):
_name(name), _maxAcceleration(maxAcceleration), _maxBrake(maxBrake),
_departure(departure), _arrival(arrival), _departureHour(departureHour){
	static uint	id = 0;

	_id = id++;
}

void	Train::pathfindingRecursive(uint recursive, vector<City*> nodes, City* pos){
	recursive--;
	nodes.push_back(pos);

	// If arrival
	if (!recursive || pos == _arrival){
		float	time = 0.f;
		for (size_t i = 1; i < nodes.size(); i++){
			Rail*	rail = nodes[i - 1]->getRailToCity(nodes[i]);
			float	speed = MAX_SPEED;

			time += rail->getLength() / speed;
		}
		return ;
	}

	for (size_t i = 0; i < pos->getRails().size(); i++){
		// If rail go to a city already in the vector
		if (find(nodes.begin(), nodes.end(), pos->getRails()[i]->getOtherPoint(pos)) != nodes.end())
			continue ;

		pathfindingRecursive(
			recursive,
			nodes,
			pos->getRails()[i]->getOtherPoint(pos)
		);
	}
}

void	Train::pathfinding(void){
	if (!_departure || !_arrival)
		return ;

	uint			recursive = MAX_RECURSIVE;
	vector<City*>	nodes;

	pathfindingRecursive(recursive, nodes, _departure);
}

void	Train::printAll(void){
	cout << "name : " << _name << '\n' <<
			"id : " << _id << '\n' <<
			"maxAcceleration : " << _maxAcceleration << '\n' <<
			"maxBrake : " << _maxBrake << '\n' <<
			"departure : " << _departure->getName() << '\n' <<
			"arrival : " << _arrival->getName() << '\n' <<
			"departureHour : " << _departureHour << endl;
}

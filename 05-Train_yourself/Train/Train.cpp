#include <Train.hpp>

Train::Train(string name, float maxAcceleration, float maxBrake, float departureHour,
City* departure, City* arrival):
_name(name), _maxAcceleration(maxAcceleration), _maxBrake(maxBrake), _departureHour(departureHour),
_departure(departure), _arrival(arrival), _time(0.f){
	static uint	id = 0;

	_id = id++;
}

void	Train::pathfindingRecursive(uint recursive, vector<City*> nodes, City* pos){
	recursive--;
	nodes.push_back(pos);

	// If arrival
	if (!recursive)
		return ;
	if (pos == _arrival){
		float	time = 0.f;
		for (size_t i = 1; i < nodes.size(); i++){
			Rail*	rail = nodes[i - 1]->getRailToCity(nodes[i]);
			float	speed = MAX_SPEED;
			time += rail->getLength() / speed;
		}
		if (_nodes.size() == 0 || time < _time){
			_nodes = nodes;
			_time = time;
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

float	getMinute(float hour){
	return (trunc((hour - trunc(hour)) / 0.0166667f));
}

void	Train::pathfinding(void){
	if (!_departure || !_arrival)
		return ;
	uint			recursive = MAX_RECURSIVE;
	vector<City*>	nodes;
	pathfindingRecursive(recursive, nodes, _departure);
	cout << "Nodes :";
	for (City* node: _nodes)
		cout << ' ' << node->getName();
	cout << "\nDeparture Hour : " << trunc(_departureHour) << 'h' << getMinute(_departureHour) <<
			"\nArrival Hour : " << trunc(_departureHour + _time) << 'h' << getMinute(_departureHour  + _time) <<
			"\nTime : " << trunc(_time) << 'h' << getMinute(_time) << endl;
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

#include <Train.hpp>

Train::Train(string name, float maxAcceleration, float maxBrake, City* departure,
City* arrival, string departureHour):
_name(name), _maxAcceleration(maxAcceleration), _maxBrake(maxBrake),
_departure(departure), _arrival(arrival), _departureHour(departureHour){
	static uint	id = 0;

	_id = id++;
}

void	Train::pathfindingRecursive(uint recursive, float distance, vector<City*> nodes, City* pos){
	nodes.push_back(pos);
	if (recursive <= 0 || pos == _arrival)
		return ;
	for (size_t i = 0; i < pos->getRails().size(); i++){
		if (find(nodes.begin(), nodes.end(), pos->getRails()[i]->getOtherPoint(pos)) != nodes.end())
			continue ;
		pathfindingRecursive(
			--recursive,
			distance + pos->getRails()[i]->getLength(),
			nodes,
			pos->getRails()[i]->getOtherPoint(pos)
		);
	}
}

void	Train::pathfinding(uint recursive){
	if (!_departure || !_arrival)
		return ;
	float			distance = 0.f;
	vector<City*>	railNodes;
	railNodes.push_back(_departure);
	for (size_t i = 0; i < _departure->getRails().size(); i++){
		pathfindingRecursive(
			recursive,
			distance + _departure->getRails()[i]->getLength(),
			railNodes,
			_departure->getRails()[i]->getOtherPoint(_departure)
		);
	}
}

void	Train::printAll(void){
	cout << "name : " << _name << '\n' <<
			"id : " << _id << '\n' <<
			"maxAcceleration : " << _maxAcceleration << '\n' <<
			"maxBrake : " << _maxBrake << '\n' <<
			"departure : " << _departure << '\n' <<
			"arrival : " << _arrival << '\n' <<
			"departureHour : " << _departureHour << endl;
}

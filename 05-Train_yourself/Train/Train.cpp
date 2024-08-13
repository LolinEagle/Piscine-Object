#include <Train.hpp>

Train::Train(string name, float maxAcceleration, float maxBrake, City* departure,
City* arrival, string departureHour):
_name(name), _maxAcceleration(maxAcceleration), _maxBrake(maxBrake),
_departure(departure), _arrival(arrival), _departureHour(departureHour){
	static uint32_t id = 0;

	_id = id++;
}

float	Train::pathfinding(void){
	if (!_departure || !_arrival)
		return (0.f);
	float	distance = 0.f;
	for (size_t i = 0; i < _departure->getRails().size(); i++){
		// Recursive
	}
	return (distance);
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

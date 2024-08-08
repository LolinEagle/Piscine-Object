#include <Train.hpp>

Train::Train(string name, uint32_t maxAcceleration, uint32_t maxBrake):
_name(name), _maxAcceleration(maxAcceleration), _maxBrake(maxBrake), _position(NULL){
	static uint32_t id = 0;

	_id = id++;
}

uint32_t	Train::pathfinding(City* city){
	if (!_position || !city)
		return (0);
	uint32_t	distance = 0;
	for (size_t i = 0; i < _position->getRails().size(); i++){
		// Recursive
	}
	return (distance);
}

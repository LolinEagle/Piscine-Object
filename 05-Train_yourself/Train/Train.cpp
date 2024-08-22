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
			time += rail->getLength() / MAX_SPEED;
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
}

void	Train::output(float t, State& state, size_t i, float d){
	cout << setfill('0') << setw(2) << trunc(t) << 'h' << setw(2) << getMinute(t) << " - " <<// 1. The time since start
			_nodes[i - 1]->getName() << "->" <<// 2. The node where the train started
			_nodes[i]->getName() << " - " <<// 3. The node where the train will arrive
			d << "km - ";// 4. The distance left to the final destination of the travel
	// 5. An indication of what the train is doing
	if (state == State::SpeedingUp) cout << "Speeding up - ";
	else if (state == State::MaintainingSpeed) cout << "Maintaining speed - ";
	else if (state == State::Bracking) cout << "Bracking - ";
	else if (state == State::Stopped) cout << "Stopped - ";
	else throw (runtime_error("Train::output(void) : Bad State"));
	// 6. A graph, representing the rail state, from the starting node to the destination node
	for (size_t ii = 0; ii < _nodes.size(); ii++){
		if (ii == i - 1) cout << '0';
		else cout << '.';
	}
	cout << endl;
}

void	Train::execute(void){
	cout << "Estimated optimal travel time : " << trunc(_time) << 'h' << getMinute(_time) << endl;
	float	t = _departureHour;
	State	state = State::SpeedingUp;
	for (size_t i = 1; i < _nodes.size(); i++){
		// Distance
		float	d = 0.f;
		for (size_t ii = i; ii < _nodes.size(); ii++){
			Rail* rail = _nodes[ii - 1]->getRailToCity(_nodes[ii]);
			d += rail->getLength();
		}

		// Output
		output(t, state, i, d);
		
		// Time
		Rail*	rail = _nodes[i - 1]->getRailToCity(_nodes[i]);// Get rail
		t += rail->getLength() / MAX_SPEED;// Add time

		// Speed
		if (state == State::SpeedingUp){
			// float	speed = 0.f, sec = 0.f, dist = 0.f;
			// while (speed < MAX_SPEED){
			// 	speed += _maxAcceleration;
			// 	dist += speed;
			// 	sec += 1.f;
			// }

			// cerr << "speed=" << speed << " sec=" << sec << " dist=" << dist << endl;
			state = State::MaintainingSpeed;
			// output(t + (sec * 0.000277778f), state, i, d - dist);
		} else if (state == State::MaintainingSpeed){

		} else if (state == State::Bracking){

		} else if (state == State::Stopped){

		} else {
			throw (runtime_error("Train::execute(void) : Bad State"));
		}
	}
	state = State::Stopped;
	output(t, state, _nodes.size(), 0.f);
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

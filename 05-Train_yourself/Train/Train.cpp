#include <Train.hpp>

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

float	Train::getMinute(float hour){
	return (trunc((hour - trunc(hour)) / 0.016666668f));
}

void	Train::outputFile(float hour, State& state, size_t i, float d){
	ofstream	file;
	file.open("Output.txt", ofstream::out | ofstream::app);

	// 1. The time since start
	file << setfill('0') << setw(2) << trunc(hour) << 'h' << setw(2) << getMinute(hour) << " - " <<
			_nodes[i]->getName() << "->" <<// 2. The node where the train started
			_nodes[i + 1]->getName() << " - ";// 3. The node where the train will arrive

	// 4. The distance left to the final destination of the travel
	file << fixed << setprecision(2) << d << "km - " << setprecision(0);

	// 5. An indication of what the train is doing
	if (state == State::SpeedingUp) file << "Speed up - ";
	else if (state == State::MaintainingSpeed) file << "Maintain - ";
	else if (state == State::Bracking) file << "Bracking - ";
	else if (state == State::Stopped) file << "Stopped - ";
	else if (state == State::PassengerDiscomfort) file << "Discomfort - ";
	else throw (runtime_error("Train::output(void) : Bad State"));

	// 6. A graph, representing the rail state, from the starting node to the destination node
	float	kmTotal = 0.f;
	for (size_t j = 1; j < _nodes.size(); j++)
		kmTotal += _nodes[j - 1]->getRailToCity(_nodes[j])->getLength();
	for (size_t j = 0; j + 1 < _nodes.size(); j++){
		Rail*	rail = _nodes[j]->getRailToCity(_nodes[j + 1]);
		for (float km = 0.f; km < rail->getLength(); km += 1.f, kmTotal -= 1.f){
			if (kmTotal > d - 1.f && kmTotal <= d) file << 'O';
			else file << '.';
		}
		file << 'X';
	}
	if (d <= 0.f) file << 'O' << endl;
	else file << '.' << endl;
	if (d <= 0.f) file << '\n';

	file.close();
}

void	Train::output(float hour, State& state, size_t i, float d){
	outputFile(hour, state, i, d);

	// 1. The time since start
	cout << setfill('0') << setw(2) << trunc(hour) << 'h' << setw(2) << getMinute(hour) << " - " <<
			_nodes[i]->getName() << "->" <<// 2. The node where the train started
			_nodes[i + 1]->getName() << " - ";// 3. The node where the train will arrive

	// 4. The distance left to the final destination of the travel
	cout << fixed << setprecision(2) << d << "km - " << setprecision(0);

	// 5. An indication of what the train is doing
	if (state == State::SpeedingUp) cout << "Speed up - ";
	else if (state == State::MaintainingSpeed) cout << "Maintain - ";
	else if (state == State::Bracking) cout << "Bracking - ";
	else if (state == State::Stopped) cout << "Stopped - ";
	else if (state == State::PassengerDiscomfort) cout << "Discomfort - ";
	else throw (runtime_error("Train::output(void) : Bad State"));

	// 6. A graph, representing the rail state, from the starting node to the destination node
	float	kmTotal = 0.f;
	for (size_t j = 1; j < _nodes.size(); j++)
		kmTotal += _nodes[j - 1]->getRailToCity(_nodes[j])->getLength();
	for (size_t j = 0; j + 1 < _nodes.size(); j++){
		Rail*	rail = _nodes[j]->getRailToCity(_nodes[j + 1]);
		for (float km = 0.f; km < rail->getLength(); km += 1.f, kmTotal -= 1.f){
			if (kmTotal > d - 1.f && kmTotal <= d) cout << 'O';
			else cout << '.';
		}
		cout << 'X';
	}
	if (d <= 0.f) cout << 'O' << endl;
	else cout << '.' << endl;
}

Train::Train(string name, float maxAcceleration, float maxBrake, float departureHour,
City* departure, City* arrival, Overtaking* overtaking):
_name(name), _maxAcceleration(maxAcceleration), _maxBrake(maxBrake), _departureHour(departureHour),
_departure(departure), _arrival(arrival), _time(0.f), _overtaking(overtaking){
	if (_overtaking == NULL)
		throw (runtime_error("Train::_overtaking can't be NULL"));
	static uint	id = 0;

	_id = id++;
}

void	Train::pathfinding(void){
	if (!_departure || !_arrival)
		return ;
	uint			recursive = MAX_RECURSIVE;
	vector<City*>	nodes;
	pathfindingRecursive(recursive, nodes, _departure);
}

void	Train::execute(void){
	float	dist, distLeft, sec, time = _departureHour;
	State	state;
	auto	events = _overtaking->getEvents();

	cout << "Train : " << _name << "\nEstimated optimal travel time : " <<
		trunc(_time) << 'h' << getMinute(_time) << endl;
	for (size_t i = 0; i + 1 < _nodes.size(); i++){
		// Distance left
		distLeft = 0.f;
		for (size_t j = i; j + 1 < _nodes.size(); j++)
			distLeft += _nodes[j]->getRailToCity(_nodes[j + 1])->getLength();

		// Stopped
		for (auto e: events){
			if (e.event == 1 && e.where == _nodes[i] && rand() % 100 < e.chance * 100){
				state = State::PassengerDiscomfort;
				output(time, state, i, distLeft);
				time += e.time;
			}
		}

		// Speeding up & Maintaining speed
		state = State::SpeedingUp;
		output(time, state, i, distLeft);
		dist = 0.f, sec = 0.f;
		for (float speed = 0.f; speed < MAX_SPEED; sec += 1.f){
			speed += _maxAcceleration;
			dist += speed / 3600.f;
		}
		state = State::MaintainingSpeed;
		output(time + (sec / 3600.f), state, i, distLeft - dist);

		// Time stamp & Distance left
		float	railLength = _nodes[i]->getRailToCity(_nodes[i + 1])->getLength();
		time += railLength / MAX_SPEED;
		distLeft -= railLength;

		// Bracking
		dist = 0.f, sec = 0.f;
		for (float speed = MAX_SPEED; speed > 0.f; sec += 1.f){
			speed -= _maxBrake;
			dist += speed / 3600.f;
		}
		state = State::Bracking;
		output(time - (sec / 3600.f), state, i + 1, distLeft + dist);
	}
	state = State::Stopped;
	output(time, state, _nodes.size() - 1, 0.f);
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

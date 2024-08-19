#include <Overtaking.hpp>

Overtaking::~Overtaking(){
	for (City* city: _citys)
		delete (city);
	for (Train* train: _trains)
		delete (train);
	for (Rail* rail: _rails)
		delete (rail);
}

City*	Overtaking::getCity(string name){
	for (City* city: _citys)
		if (city->getName() == name) return (city);
	return (NULL);
}

Train*	Overtaking::getTrain(string name){
	for (Train* train: _trains)
		if (train->getName() == name) return (train);
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

void	Overtaking::addRail(Rail* rail){
	if (find(_rails.begin(), _rails.end(), rail) == _rails.end())
		_rails.push_back(rail);
}

void	Overtaking::inputRailNetwork(const string &filepath){
	ifstream	file(filepath.data());
	string		line;

	while (getline(file, line)){
		istringstream	iss(line);
		string			token;

		iss >> token;
		if (token == "Node"){
			iss >> token;
			if (token.find("City") != string::npos){
				City*	city = new City(token);
				addCity(city);
			} else {
				City*	node = new RailNode(token);
				addCity(node);
			}
		} else if (token == "Event"){
			iss >> token;
			// Event
		} else if (token == "Rail"){
			string	a, b;
			float	length;
			iss >> a >> b >> token;
			length = stof(token);
			Rail*	rail = new Rail(MAX_SPEED, length, getCity(a), getCity(b));
			addRail(rail);
			getCity(a)->addRail(rail);
			getCity(b)->addRail(rail);
		} else {
			throw (runtime_error("inputRailNetwork() : Bad token"));
		}
	}
}

void	Overtaking::inputTrainComposition(const string &filepath){
	ifstream	file(filepath.data());
	string		line;

	while (getline(file, line)){
		istringstream	iss(line);
		string			token;

		string	name, hour;
		float	maxAcceleration, maxBrake;
		City*	departure;
		City*	arrival;

		iss >> name;// 1. a name
		iss >> token;
		maxAcceleration = stof(token);// 2. the maximum acceleration force
		iss >> token;
		maxBrake = stof(token);// 3. the maximum brake force
		iss >> token;
		departure = getCity(token);// 4. the departure train station
		if (departure == NULL)
			cout << YELLOW << "Warning : " << name << " departure is not set" << ENDL;
		iss >> token;
		arrival = getCity(token);// 5. the arrival train station
		if (arrival == NULL)
			cout << YELLOW << "Warning : " << name << " arrival is not set" << ENDL;
		iss >> hour;// 6. the hour of departure
	
		Train*	train = new Train(name, maxAcceleration, maxBrake, departure, arrival, hour);
		addTrain(train);
	}
}

#include <Overtaking.hpp>

Overtaking*	Overtaking::_instance = NULL;

Overtaking*	Overtaking::getInstance(void){
	if (_instance == NULL)
		_instance = new Overtaking();
	return (_instance);
}

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

	if (!file.is_open()){
		cerr << RED << "Error opening file : " << filepath << ENDL;
		return ;
	}
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
			s_event	e;

			// Event
			iss >> token;
			if (token.find("Riot") != string::npos)
				e.event = Event::Riot;
			else if (token.find("Passenger's_Discomfort") != string::npos)
				e.event = Event::PassengersDiscomfort;
			else
				continue ;

			// Chance
			iss >> token;
			e.chance = stof(token);
			if (e.chance <= 0.f) continue ;

			// Time
			iss >> token;
			if (token.find('m') != string::npos){
				size_t	pos = token.find('m');
				string	sub = token.substr(0, pos);
				e.time = stof(sub) * 0.0166667f;
			} else if (token.find('h') != string::npos){
				size_t	pos = token.find('h');
				string	sub = token.substr(0, pos);
				e.time = stof(sub);
			} else if (token.find('d') != string::npos){
				size_t	pos = token.find('d');
				string	sub = token.substr(0, pos);
				e.time = stof(sub) * 24;
			} else {
				continue ;
			}

			// Where
			iss >> token;
			e.where = getCity(token);
			if (e.where == NULL) continue ;

			_events.push_back(e);
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

bool	isNumber(const string& s){
	return (!s.empty() && find_if(s.begin(), s.end(), [](unsigned char c){
		return (!isdigit(c) && c != '.' && c != 'h');
	}) == s.end());
}

void	Overtaking::inputTrainComposition(const string &filepath){
	ifstream	file(filepath.data());
	string		line;

	if (!file.is_open()){
		cerr << RED << "Error opening file : " << filepath << ENDL;
		return ;
	}
	while (getline(file, line)){
		istringstream	iss(line);
		string			token;

		string	name;
		float	maxAcceleration, maxBrake, hour;
		City*	departure;
		City*	arrival;

		iss >> name;// 1. a name

		iss >> token;
		if (!isNumber(token))
			throw (runtime_error("Overtaking::inputTrainComposition() : Bad input"));
		maxAcceleration = stof(token);// 2. the maximum acceleration force

		iss >> token;
		if (!isNumber(token))
			throw (runtime_error("Overtaking::inputTrainComposition() : Bad input"));
		maxBrake = stof(token);// 3. the maximum brake force

		iss >> token;
		departure = getCity(token);// 4. the departure train station
		if (departure == NULL)
			cout << YELLOW << "Warning : " << name << " departure is not set" << ENDL;

		iss >> token;
		arrival = getCity(token);// 5. the arrival train station
		if (arrival == NULL)
			cout << YELLOW << "Warning : " << name << " arrival is not set" << ENDL;

		iss >> token;
		if (!isNumber(token))
			throw (runtime_error("Overtaking::inputTrainComposition() : Bad input"));
		size_t	pos = token.find('h');
		string	sub = token.substr(0, pos);
		hour = stof(sub);
		sub = token.substr(pos + 1);
		hour += stof(sub) * 0.0166667f;// 6. the hour of departure
	
		if (maxAcceleration < 0.5f || maxBrake < 0.5f){
			cout << YELLOW << "Warning : Train can't have acceleration or brake speed under 0.5 " <<
					name << " is not added to the train composition" << ENDL;
			continue ;
		}
		Train*	train = new Train(name, maxAcceleration, maxBrake, hour, departure, arrival, this);
		addTrain(train);
	}
}

#include <City.hpp>
#include <Overtaking.hpp>
#include <Train.hpp>

void	inputRailNetwork(const string &filepath, Overtaking& overtaking){
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
				overtaking.addCity(city);
			} else {
				// Node
			}
		} else if (token == "Event"){
			iss >> token;
			// Event
		} else if (token == "Rail"){
			iss >> token;
			// Rail
		} else {
			throw (runtime_error("inputRailNetwork() : Bad token"));
		}
	}
}

void	inputTrainComposition(const string &filepath, Overtaking& overtaking){
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
		departure = overtaking.getCity(token);// 4. the departure train station
		if (departure == NULL)
			cout << YELLOW << "Warning : " << name << " departure is not set" << ENDL;
		iss >> token;
		arrival = overtaking.getCity(token);// 5. the arrival train station
		if (arrival == NULL)
			cout << YELLOW << "Warning : " << name << " arrival is not set" << ENDL;
		iss >> hour;// 6. the hour of departure
		Train*	train = new Train(name, maxAcceleration, maxBrake, departure, arrival, hour);
		overtaking.addTrain(train);
	}
}

int	main(void){
	Overtaking	overtaking;

	inputRailNetwork("RailNetwork", overtaking);
	inputTrainComposition("TrainComposition", overtaking);
	cout << BLUE << "Overtaking number of Citys : " << overtaking.getCitys().size() << ENDL;
	cout << BLUE << "Overtaking number of Trains : " << overtaking.getTrains().size() << ENDL;
	return (0);
}

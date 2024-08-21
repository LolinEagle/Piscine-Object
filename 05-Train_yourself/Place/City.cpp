#include <City.hpp>

void	City::addRail(Rail* rail){
	if (find(_rails.begin(), _rails.end(), rail) == _rails.end())
		_rails.push_back(rail);
}

void	City::event(Event e){
	if (e == Event::Riot){

	} else if (e == Event::PassengersDiscomfort){

	} else {
		throw (runtime_error("Bad event"));
	}
}

Rail*	City::getRailToCity(City* city){
	for (Rail* rail: _rails){
		if (rail->getOtherPoint(this) == city)
			return (rail);
	}
	return (NULL);
}

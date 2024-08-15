#include <City.hpp>

void	City::addRail(Rail* rail){
	if (find(_rails.begin(), _rails.end(), rail) == _rails.end())
		_rails.push_back(rail);
}

void	City::event(Event e){
	if (e == Event::Riot){

	} else if (e == Event::PassengersDiscomfort){

	} else if (e == Event::CantHappen){

	} else {
		throw (runtime_error("Bad event"));
	}
}

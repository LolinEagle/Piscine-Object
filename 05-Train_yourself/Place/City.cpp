#include <City.hpp>

void	City::addRail(Rail* rail){
	if (find(_rails.begin(), _rails.end(), rail) == _rails.end())
		_rails.push_back(rail);
}

Rail*	City::getRailToCity(City* city){
	for (Rail* rail: _rails){
		if (rail->getOtherPoint(this) == city)
			return (rail);
	}
	return (NULL);
}

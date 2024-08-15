#include <Rail.hpp>

City*	Rail::getPoint(char c){
	if (c == 'A' || c == 'a')
		return (_pointA);
	if (c == 'B' || c == 'b')
		return (_pointB);
	throw (runtime_error("Rail::getPoint(char c)"));
}

void	Rail::setPoint(City* point){
	if (!point)
		return ;
	if (_pointA == NULL){
		_pointA = point;
		point->addRail(this);
	} else if  (_pointB == NULL && _pointA != point){
		_pointB = point;
		point->addRail(this);
	} else {
		throw (runtime_error("Rail::setPoint(City* point)"));
	}
}

void	Rail::event(Event e){
	if (e == Event::Riot){

	} else if (e == Event::PassengersDiscomfort){

	} else if (e == Event::CantHappen){

	} else {
		throw (runtime_error("Bad event"));
	}
}

City*	Rail::getOtherPoint(City* point){
	if (point == _pointA)
		return (_pointB);
	else if (point == _pointB)
		return (_pointA);
	throw (runtime_error("Rail::getOtherPoint(City* point)"));
	return (NULL);
}

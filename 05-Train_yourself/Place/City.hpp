#pragma once

#include <Rail.hpp>

class Rail;

class City{
protected:
	string			_name;
	vector<Rail*>	_rails;
public:
	City(string name): _name(name){}
	~City(){}
	
	string			getName(void){return (_name);}
	vector<Rail*>	getRails(void){return (_rails);}

	// Command
	void	addRail(Rail* rail);

	Rail*	getRailToCity(City* city);
};

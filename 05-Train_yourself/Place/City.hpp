#pragma once

#include <header.hpp>
#include <Rail.hpp>

class Rail;

class City{
private:
	string			_name;
	vector<Rail*>	_rails;
public:
	City(string name): _name(name){}
	~City(){}
	
	string			getName(void){return (_name);}
	vector<Rail*>	getRails(void){return (_rails);}

	void	addRail(Rail* rail);
};

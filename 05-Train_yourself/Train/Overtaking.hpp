#pragma once

#include <Train.hpp>

class Overtaking{
private:
	vector<City*>	_citys;
	vector<Train*>	_trains;
public:
	Overtaking(void){}
	~Overtaking();

	City*			getCity(string name);
	Train*			getTrain(string name);
	vector<City*>	getCitys(void){return (_citys);}
	vector<Train*>	getTrains(void){return (_trains);}
	void			setCitys(vector<City*> citys){_citys = citys;}
	void			setTrains(vector<Train*> trains){_trains = trains;}

	void	addCity(City* city);
	void	addTrain(Train* train);
};

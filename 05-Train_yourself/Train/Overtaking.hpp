#pragma once

#include <RailNode.hpp>
#include <Train.hpp>

class Train;

class Overtaking{
private:
	struct s_event{
		Event	event;
		float	chance;
		float	time;
		City*	where;
	};

	vector<City*>	_citys;
	vector<Train*>	_trains;
	vector<Rail*>	_rails;
	vector<s_event>	_events;
public:
	Overtaking(void){}
	~Overtaking();

	City*			getCity(string name);
	Train*			getTrain(string name);
	vector<City*>	getCitys(void){return (_citys);}
	vector<Train*>	getTrains(void){return (_trains);}
	vector<Rail*>	getRails(void){return (_rails);}
	vector<s_event>	getEvents(void){return (_events);}
	void			setCitys(vector<City*> citys){_citys = citys;}
	void			setTrains(vector<Train*> trains){_trains = trains;}
	void			setRails(vector<Rail*> rails){_rails = rails;}

	void	addCity(City* city);
	void	addTrain(Train* train);
	void	addRail(Rail* rail);

	void	inputRailNetwork(const string &filepath);
	void	inputTrainComposition(const string &filepath);
};

#include <City.hpp>
#include <Overtaking.hpp>
#include <Train.hpp>

void	output(Train* train){
	cout << MAGENTA << "------------------------------------------------------------------" << ENDL;
	train->pathfinding();
	train->execute();
}

int	main(void){
	Overtaking	overtaking;

	overtaking.inputRailNetwork("RailNetwork");
	overtaking.inputTrainComposition("TrainComposition");
	cout << BLUE << "Number of Citys / Nodes : " << overtaking.getCitys().size() << ENDL;
	cout << BLUE << "Number of Trains : " << overtaking.getTrains().size() << ENDL;
	cout << BLUE << "Number of Rails : " << overtaking.getRails().size() << ENDL;

	Train*	ab1 = overtaking.getTrain("TrainAB1");
	Train*	ac1 = overtaking.getTrain("TrainAC");
	Train*	ab2 = overtaking.getTrain("TrainAB2");
	bool	a = true, b = true, c = true;

	srand(time(NULL));
	for (auto e: overtaking.getEvents()){
		if (e.event == 0 && e.where->getName() == "CityA" && rand() % 100 < e.chance * 100)
			a = false;
		else if (e.event == 0 && e.where->getName() == "CityB" && rand() % 100 < e.chance * 100)
			b = false;
		else if (e.event == 0 && e.where->getName() == "CityC" && rand() % 100 < e.chance * 100)
			c = false;
	}
	if (a && b) output(ab1);
	if (a && c) output(ac1);
	if (a && b) output(ab2);
	return (0);
}

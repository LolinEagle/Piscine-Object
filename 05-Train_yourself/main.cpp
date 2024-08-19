#include <City.hpp>
#include <Overtaking.hpp>
#include <Train.hpp>

int	main(void){
	Overtaking	overtaking;

	overtaking.inputRailNetwork("RailNetwork");
	overtaking.inputTrainComposition("TrainComposition");
	cout << BLUE << "Overtaking number of Citys / Nodes : " << overtaking.getCitys().size() << ENDL;
	cout << BLUE << "Overtaking number of Trains : " << overtaking.getTrains().size() << ENDL;
	cout << BLUE << "Overtaking number of Rails : " << overtaking.getRails().size() << ENDL;
	cout << MAGENTA << "------------------ TrainAB1 ------------------" << ENDL;
	overtaking.getTrain("TrainAB1")->pathfinding();
	cout << MAGENTA << "------------------ TrainAC -------------------" << ENDL;
	overtaking.getTrain("TrainAC")->pathfinding();
	cout << MAGENTA << "------------------ TrainAB2 ------------------" << ENDL;
	overtaking.getTrain("TrainAB2")->pathfinding();
	return (0);
}

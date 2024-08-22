#include <City.hpp>
#include <Overtaking.hpp>
#include <Train.hpp>

void	train(Train* train){
	cout << "Train : " << train->getName() << endl;
	train->pathfinding();
	train->execute();
}

int	main(void){
	Overtaking	overtaking;

	overtaking.inputRailNetwork("RailNetwork");
	overtaking.inputTrainComposition("TrainComposition");
	cout << BLUE << "Overtaking number of Citys / Nodes : " << overtaking.getCitys().size() << ENDL;
	cout << BLUE << "Overtaking number of Trains : " << overtaking.getTrains().size() << ENDL;
	cout << BLUE << "Overtaking number of Rails : " << overtaking.getRails().size() << ENDL;

	cout << MAGENTA << "------------------ TrainAB1 ------------------" << ENDL;
	train(overtaking.getTrain("TrainAB1"));
	cout << MAGENTA << "------------------ TrainAC -------------------" << ENDL;
	train(overtaking.getTrain("TrainAC"));
	cout << MAGENTA << "------------------ TrainAB2 ------------------" << ENDL;
	train(overtaking.getTrain("TrainAB2"));
	return (0);
}

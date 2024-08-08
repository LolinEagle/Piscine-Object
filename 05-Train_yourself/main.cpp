#include <City.hpp>
#include <Overtaking.hpp>
#include <Train.hpp>

int	main(void){
	City		cityA("Paris");
	City		cityB("Marseille");
	City		cityC("Lyon");

	Overtaking	overtaking;

	Rail		rail1(1);
	Rail		rail2(1);
	Rail		rail3(1);

	Train		train("Train", 1, 1);

	rail1.setPoint(&cityA);
	rail1.setPoint(&cityB);
	cout << GREEN << "Is rail1 connect to cityA : " << (rail1.getPoint('A') == &cityA) << ENDL;
	cout << GREEN << "Is rail1 connect to cityB : " << (rail1.getPoint('B') == &cityB) << ENDL;

	overtaking.addTrain(&train);
	cout << CYAN << "Overtaking numbers of trains : " << overtaking.getTrains().size() << ENDL;

	rail2.setPoint(&cityB);
	rail2.setPoint(&cityC);
	rail3.setPoint(&cityC);
	rail3.setPoint(&cityA);
	train.setPosition(&cityA);
	cout << BLUE << "cityA numbers of rails : " << cityA.getRails().size() << ENDL;
	cout << BLUE << "cityB numbers of rails : " << cityB.getRails().size() << ENDL;
	cout << BLUE << "cityC numbers of rails : " << cityC.getRails().size() << ENDL;

	return (0);
}

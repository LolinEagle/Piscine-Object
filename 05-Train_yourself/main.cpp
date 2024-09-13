#include <Facade.hpp>

int	main(int ac, char** av){
	if (ac != 3){
		cerr << "./train.out <Network> <Trains>" << endl;
		return (1);
	}
	try {
		Facade		facade(av[1], av[2]);

		srand(time(NULL));
		facade.output();
	} catch(const exception& e){
		cerr << e.what() << '\n';
		delete (Overtaking::getInstance());
	}
	return (0);
}

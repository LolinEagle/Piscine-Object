#include <Facade.hpp>

int	main(int ac, char** av){
	if (ac != 3){
		cerr << "./train.out <Network> <Trains>" << endl;
		return (1);
	}
	try {
		Facade		facade(av[1], av[2]);
		ofstream	file;

		file.open("Output.txt", ofstream::out | ofstream::trunc);
		file.close();
		srand(time(NULL));
		facade.output();
	} catch(const exception& e){
		cerr << e.what() << '\n';
	}
	return (0);
}

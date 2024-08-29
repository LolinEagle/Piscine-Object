#include <Facade.hpp>

int	main(void){
	Facade	facade("RailNetwork", "TrainComposition");

	srand(time(NULL));
	facade.output();
	return (0);
}

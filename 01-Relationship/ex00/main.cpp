#include <Relationship.hpp>

int	main(void){
	Worker		worker1;
	Worker		worker2;
	Worker		worker3;

	Shovel		shovel;
	Hammer		hammer;

	Workshop	workshop1;
	Workshop	workshop2;

	worker1.takeTool(&shovel);
	worker2.takeTool(&hammer);
	worker1.giveTool();
	worker3.takeTool(&shovel);

	workshop1.workshopRegister(&worker1);
	workshop2.workshopRegister(&worker1);

	workshop1.executeWorkDay();
	workshop2.executeWorkDay();

	return (0);
}

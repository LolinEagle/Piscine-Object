#include <Tool.hpp>
#include <Worker.hpp>
#include <Workshop.hpp>

int	main(void){
	Worker		worker1;
	Worker		worker2;
	Worker		worker3;

	Shovel		shovel;
	Hammer		hammer;

	Workshop	workshop1("Shovel");
	Workshop	workshop2("Hammer");

	worker1.takeTool(&shovel);
	cout << "Should not be null:" << worker1.getTool<Shovel>() << endl;
	cout << "Should be null:" << worker1.getTool<Hammer>() << endl;
	worker2.takeTool(&hammer);
	worker1.giveTool();
	worker3.takeTool(&shovel);

	workshop1.workshopRegister(&worker1);
	workshop2.workshopRegister(&worker1);
	workshop1.executeWorkDay();
	workshop2.executeWorkDay();

	return (0);
}

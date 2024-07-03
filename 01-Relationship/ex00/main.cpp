#include <Tool.hpp>
#include <Worker.hpp>
#include <Workshop.hpp>

int	main(void){
	Worker		worker1;
	Worker		worker2;
	Worker		worker3;
	Worker		worker4;
	Worker		worker5;

	Shovel		shovel1;
	Shovel		shovel2;
	Shovel		shovel3;
	Hammer		hammer1;
	Hammer		hammer2;

	Workshop	workshop1("Shovel");
	Workshop	workshop2("Hammer");
	Workshop	workshop3;

	worker1.takeTool(&shovel2);
	cout << "Should not be null:" << worker1.getTool<Shovel>() << endl;
	cout << "Should be null:" << worker1.getTool<Hammer>() << endl;
	worker2.takeTool(&shovel2);
	cout << "Should be null:" << worker1.getTool() << endl;
	worker1.takeTool(&shovel1);
	worker3.takeTool(&shovel3);
	worker4.takeTool(&hammer1);
	worker5.takeTool(&hammer2);

	workshop1.workshopRegister(&worker1);
	workshop1.workshopRegister(&worker2);
	workshop1.workshopRegister(&worker3);
	workshop1.workshopRegister(&worker4);

	workshop2.workshopRegister(&worker4);
	workshop2.workshopRegister(&worker5);
	workshop2.workshopRegister(&worker3);

	workshop3.workshopRegister(&worker1);
	workshop3.workshopRegister(&worker2);
	workshop3.workshopRegister(&worker3);
	workshop3.workshopRegister(&worker4);
	workshop3.workshopRegister(&worker5);
	workshop3.workshopRegister(&worker5);

	cout << "Workshop 1:" << endl;
	workshop1.executeWorkDay();
	cout << "Workshop 2:" << endl;
	workshop2.executeWorkDay();
	cout << "Workshop 3:" << endl;
	workshop3.executeWorkDay();

	return (0);
}

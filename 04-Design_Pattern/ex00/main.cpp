#include <Course.hpp>
#include <Form.hpp>
#include <Person.hpp>
#include <Room.hpp>

int	main(void){
	Room	room;
	Person	a("a");
	Person	b("b");
	Person	c("c");

	room.enter(&a);
	room.enter(&b);
	room.enter(&c);
	room.printOccupant();

	Headmaster			s("Staf");
	CourseFinishedForm	form;

	s.sign(&form);
	s.receiveForm(&form);
	cout << s.getFormToValidate().size() << endl;
	return (0);
}

#pragma once

#include <Datas.hpp>
#include <Person.hpp>

class Room{
private:
	size_t			_id;
	vector<Person*>	_occupants;
public:
	Room(void);

	bool	canEnter(Person* person);
	void	enter(Person* person);
	void	exit(Person* person);
	void	printOccupant(void);
};

class Classroom: public Room{
private:
	Course*	_currentRoom;
public:
	Classroom(void): _currentRoom(NULL){}
	void	assignCourse(Course* course){_currentRoom = course;}
};

class SecretarialOffice: public Room{
private:
	vector<Form*>	_archivedForms;
};

class HeadmasterOffice: public Room{
};

class StaffRestRoom: public Room{
};

class Courtyard: public Room{
};

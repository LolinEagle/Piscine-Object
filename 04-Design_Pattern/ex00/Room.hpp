#pragma once

#include <Datas.hpp>

using namespace std;

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

Room::Room(void){
	static size_t id = 0;

	_id = id++;
}

bool	Room::canEnter(Person* person){
	(void)person;
	cout << "TODO" << endl;
	return (0);
}

void	Room::enter(Person* person){
	if (find(_occupants.begin(), _occupants.end(), person) == _occupants.end())
		_occupants.push_back(person);
}

void	Room::exit(Person* person){
	auto	it = find(_occupants.begin(), _occupants.end(), person);
	if (it != _occupants.end())
		_occupants.erase(it);
}

void	Room::printOccupant(void){
	cout << "TODO" << endl;
}

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

class HeadmasterOffice : public Room{
};

class StaffRestRoom : public Room{
};

class Courtyard : public Room{
};

#pragma once

#include <Datas.hpp>

using namespace std;

class Room{
private:
	size_t			ID;
	vector<Person*>	_occupants;
public:
	Room(void);

	bool canEnter(Person*);
	void	enter(Person*);
	void	exit(Person*);
	
	void	printOccupant(void);
};

class Classroom : public Room{
private:
	Course* _currentRoom;

public:
	Classroom(void);
	void	assignCourse(Course* p_course);
};

class SecretarialOffice: public Room{
private:
	vector<Form*> _archivedForms;
};

class HeadmasterOffice : public Room{
};

class StaffRestRoom : public Room{
};

class Courtyard : public Room{
};

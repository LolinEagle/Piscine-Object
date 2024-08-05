#pragma once

#include <Datas.hpp>
#include <Person.hpp>

enum class Event{
	RingBell
};

class Observer{
private:
	Professor*			_professor;
	vector<Student*>	_students;
	Course*				_course;
	bool 				_ringBell;
public:
	Observer(Course* course): _professor(NULL), _course(course), _ringBell(false){}

	void	executeEvent(Event event, Headmaster* headmaster);
};

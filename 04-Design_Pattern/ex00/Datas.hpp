#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <Form.hpp>
#include <Person.hpp>
#include <Room.hpp>

using namespace std;

class Student;
class Professor;

class Course{
private:
	string				_name;
	Professor*			_responsable;
	vector<Student*>	_students;
	int					_numberOfClassToGraduate;
	int					_maximumNumberOfStudent;
public:
	Course(string name):
	_name(name), _responsable(NULL), _numberOfClassToGraduate(0), _maximumNumberOfStudent(0){}

	int		getNumberOfClassToGraduate(void){return (_numberOfClassToGraduate);}
	int		getMaximumNumberOfStudent(void){return (_maximumNumberOfStudent);}
	void	assign(Professor* professor){_responsable = professor;}
	void	subscribe(Student* student);
};

void	Course::subscribe(Student* student){
	if (find(_students.begin(), _students.end(), student) == _students.end())
		_students.push_back(student);
}

enum class Event{
	RingBell
};

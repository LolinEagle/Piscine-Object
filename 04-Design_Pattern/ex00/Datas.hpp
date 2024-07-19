#pragma once

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
	Course(string p_name);

	void	assign(Professor* p_professor);
	void	subscribe(Student* p_student);
};

enum class Event{
	RingBell
};

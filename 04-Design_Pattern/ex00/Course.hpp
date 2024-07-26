#pragma once

#include <Datas.hpp>

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
	void	graduate(void){_numberOfClassToGraduate++;}
};

enum class Event{
	RingBell
};

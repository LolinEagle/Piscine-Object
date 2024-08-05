#pragma once

#include <Datas.hpp>

class Student;
class Professor;
class Headmaster;

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

	string				getName(void){return (_name);}
	Professor*			getResponsable(void){return (_responsable);}
	vector<Student*>	getStudent(void){return (_students);}
	int					getNumberOfClassToGraduate(void){return (_numberOfClassToGraduate);}
	int					getMaximumNumberOfStudent(void){return (_maximumNumberOfStudent);}

	void	assign(Professor* professor);
	void	assign(Professor* professor, Headmaster* headmaster);
	void	subscribe(Student* student);
	void	unSubscribe(Student* student);
	void	graduate(void){_numberOfClassToGraduate++;}
};

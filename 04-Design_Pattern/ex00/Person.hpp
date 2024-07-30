#pragma once

#include <Datas.hpp>
#include <Course.hpp>
#include <Form.hpp>
#include <Room.hpp>

enum class FormType;
class Form;
class GraduateStudentForm;
class Room;
class Classroom;
class Secretary;

class Person{
protected:
	string	_name;
	Room*	_currentRoom;
public:
	Person(string name): _name(name), _currentRoom(NULL){}

	string	getName(void){return (_name);}
	Room*	room(void){return (_currentRoom);}
};

class Staff: public Person{
public:
	Staff(string name): Person(name){}

	void	sign(Form* form);
};

class Student: public Person{
private:
	vector<Course*>	_subscribedCourse;
public:
	Student(string name): Person(name){}

	void	attendClass(Classroom* classroom);
	void	exitClass(void){_subscribedCourse.clear();}
	void	graduate(Course* course){course->graduate();}
};

class Headmaster: public Staff{
private:
	vector<Form*>	_formToValidate;
	Secretary*		_secretary;
public:
	Headmaster(string name): Staff(name), _secretary(NULL){}

	vector<Form*>	getFormToValidate(void){return (_formToValidate);}
	void			setSecretary(Secretary* secretary){_secretary = secretary;}

	void	receiveForm(Form* form);
	void	executeForm(void);
	void	assignProfessorToCourse(Professor* professor, Course* course);

	GraduateStudentForm*	receiveGraduateStudentForm(void);
	void					confirmGraduation(GraduateStudentForm* form);
};

class Secretary: public Staff{
public:
	Secretary(string name): Staff(name){}

	Form*	createForm(FormType formType);
	void	archiveForm(Form* form);
};

class Professor: public Staff{
private:
	Course*	_currentCourse;
public:
	Professor(string name): Staff(name), _currentCourse(NULL){}

	void	assignCourse(Course* course);
	void	doClass(void);
	void	closeCourse(void);
	void	graduateStudent(Headmaster* headmaster, Student* student, Course* course);
	void	fillGraduateStudentForm(GraduateStudentForm* form);
};

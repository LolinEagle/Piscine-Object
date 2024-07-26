#pragma once

#include <Datas.hpp>
#include <Course.hpp>
#include <Form.hpp>

class Classroom;
class Room;

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

	void	sign(Form* form){cout << *form << " is signed" << endl;}
};

class Student: public Person{
private:
	vector<Course*>	_subscribedCourse;
public:
	Student(string name): Person(name){}

	void	attendClass(Classroom* classroom);
	void	exitClass(void);
	void	graduate(Course* course);
};

class Headmaster: public Staff{
private:
	vector<Form*>	_formToValidate;
public:
	Headmaster(string name): Staff(name){}

	vector<Form*>	getFormToValidate(void){return (_formToValidate);}
	void			receiveForm(Form* form);
};

class Secretary: public Staff{
public:
	Secretary(string name): Staff(name){}

	Form*	createForm(FormType formType);
	void	archiveForm(void);
};

class Professor: public Staff{
private:
	Course*	_currentCourse;
public:
	Professor(string name): Staff(name){}

	void	assignCourse(Course* course);
	void	doClass(void);
	void	closeCourse(void);
};

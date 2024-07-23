#pragma once

#include <Datas.hpp>

using namespace std;

class Classroom;
class Course;
class Room;

class Person{
protected:
	string	_name;
	Room*	_currentRoom;
public:
	Person(string name): _name(name), _currentRoom(NULL){}

	Room*	room(void){return (_currentRoom);}
};

class Staff: public Person{
public:
	void	sign(Form* form){cout << form << "is signed" << endl;}
};

class Student: public Person{
private:
	vector<Course*>	_subscribedCourse;
public:
	void	attendClass(Classroom* classroom){(void)classroom; cout << "TODO" << endl;}
	void	exitClass(void){_currentRoom = NULL;}
	void	graduate(Course* course){(void)course; cout << "TODO" << endl;}
};

class Headmaster: public Staff{
private:
	vector<Form*>	_formToValidate;
public:
	void	receiveForm(Form* form){
		if (find(_formToValidate.begin(), _formToValidate.end(), form) == _formToValidate.end())
			_formToValidate.push_back(form);
	}
};

class Secretary: public Staff{
public:
	Form*	createForm(FormType formType){(void)formType; cout << "TODO" << endl; return (NULL);}
	void	archiveForm(void){cout << "TODO" << endl;}
};

class Professor: public Staff{
private:
	Course*	_currentCourse;
public:
	void	assignCourse(Course* course){_currentCourse = course;}
	void	doClass(void){cout << "TODO" << endl;}
	void	closeCourse(void){_currentCourse = NULL;}
};

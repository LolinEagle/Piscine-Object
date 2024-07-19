#pragma once

#include <Datas.hpp>

using namespace std;

class Classroom;
class Course;
class Room;

class Person{
private:
	string	_name;
	Room*	_currentRoom;
public:
	Person(string p_name);

	Room*	room(void){return (_currentRoom);}
};

class Staff : public Person{
public:
	void	sign(Form* p_form);
};

class Student : public Person{
private:
	vector<Course*>	_subscribedCourse;
public:
	void	attendClass(Classroom* p_classroom);
	void	exitClass(void);
	void	graduate(Course* p_course);
};

class Headmaster : public Staff{
private:
	vector<Form*>	_formToValidate;
public:
	void	receiveForm(Form* p_form);
};

class Secretary : public Staff{
public:
	Form*	createForm(FormType p_formType);
	void	archiveForm(void);
};

class Professor : public Staff{
private:
	Course*	_currentCourse;
public:
	void	assignCourse(Course* p_course);
	void	doClass(void);
	void	closeCourse(void);
};

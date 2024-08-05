#pragma once

#include <Datas.hpp>
#include <Course.hpp>
#include <Form.hpp>
#include <Observer.hpp>
#include <Room.hpp>

enum class FormType;
enum class Event;
class Form;
class SubscriptionToCourseForm;
class GraduateStudentForm;
class StudentJoinCouseForm;
class Observer;
class Room;
class Classroom;
class Headmaster;
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

	vector<Course*>	getSubscribedCourse(void){return (_subscribedCourse);}

	void	attendClass(Classroom* classroom);
	void	exitClass(Course* course);
	void	exitAllClass(void){_subscribedCourse.clear();}

	void	graduate(Course* course){course->graduate();}
	void	subscribedCourse(Course* course);
	void	lookForNewCourse(Headmaster* headmaster, Course* course);
	void	learn(string str){cout << "I learn this: " << str << endl;}
};

class Headmaster: public Staff{
private:
	vector<Form*>	_formToValidate;
	Secretary*		_secretary;
public:
	Headmaster(string name): Staff(name), _secretary(NULL){}

	vector<Form*>	getFormToValidate(void){return (_formToValidate);}
	Secretary*		getSecretary(void){return (_secretary);}
	void			setSecretary(Secretary* secretary){_secretary = secretary;}

	void	receiveForm(Form* form);
	void	executeForm(void);
	void	assignProfessorToCourse(Professor* professor, Course* course);
	void	assignStudentToCourse(Student* student, Course* course);

	SubscriptionToCourseForm*	receiveSubscriptionToCourseForm(void);
	GraduateStudentForm*		receiveGraduateStudentForm(void);
	StudentJoinCouseForm*		receiveStudentJoinCouseForm(void);
	void	confirmAssignCourse(SubscriptionToCourseForm* form);
	void	confirmGraduation(GraduateStudentForm* form);
	void	confirmCourseSubscription(StudentJoinCouseForm* form);

	Classroom*	getNewClassroom(void);
	void		executeEvent(Observer* observer, Event event);
};

class Secretary: public Staff{
public:
	Secretary(string name): Staff(name){}

	Form*	createForm(FormType formType);
	void	archiveForm(Form* form);
};

class Professor: public Staff{
private:
	Course*		_currentCourse;
	Classroom*	_classroom;
public:
	Professor(string name): Staff(name), _currentCourse(NULL), _classroom(NULL){}
	~Professor();

	Course*	getCurrentCourse(void){return (_currentCourse);}
	void	setCurrentCourse(Course* course){_currentCourse = course;}
	void	setClassroom(Classroom* classroom){_classroom = classroom;}

	void	assignCourse(Course* course, Headmaster* headmaster);
	void	doClass(Headmaster* headmaster);
	void	closeCourse(void);

	void	graduateStudent(Headmaster* headmaster, Student* student, Course* course);
	void	fillGraduateStudentForm(GraduateStudentForm* form);
	void	learnStudent(Student* student, string str);
};

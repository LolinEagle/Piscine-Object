#pragma once

#include <Course.hpp>
#include <Person.hpp>

class School{
private:
	vector<Course*>		_courses;
	vector<Observer*>	_observers;
	vector<Student*>	_students;
	vector<Professor*>	_professors;
	Headmaster			_headmaster = Headmaster("Headmaster");
	Secretary			_secretary = Secretary("Secretary");
public:
	School(void){_headmaster.setSecretary(&_secretary);}
	~School(){}

	Course*				getCourse(string name);
	vector<Course*>		getAllCourses(void){return (_courses);}
	vector<Student*>	getStudents(void){return (_students);}
	vector<Professor*>	getProfessors(void){return (_professors);}
	Headmaster*			getHeadmaster(void){return (&_headmaster);}
	Secretary*			getSecretary(void){return (&_secretary);}

	void	runDayRoutine(void);
	void	launchClasses(void);
	void	requestRingBell(void);
	void	addCourse(Course* course);
	void	addObserver(Observer* observer);
	void	recruteProfessor(Professor* professor);
	void	recruteStudent(Student* student);
	void	graduationCeremony(void);
};

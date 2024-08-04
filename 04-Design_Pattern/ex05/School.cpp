#include <School.hpp>

Course*	School::getCourse(string name){
	for (auto course: _courses){
		if (course->getName() == name)
			return (course);
	}
	return (NULL);
}

void	School::runDayRoutine(void){
	// 1. launch classes
	launchClasses();
	// 2. allow student and professor to go on recreation
	// 3. launch classes
	// 4. launch lunch
	// 5. launch classes
	// 6. allow student and professor to go on recreation
	// 7. launch classes
	for (int i = 0; i < 6; i++)
		requestRingBell();
}

void	School::launchClasses(void){
	for (auto student: _students){
		for (auto course: _courses)
			_headmaster.assignStudentToCourse(student, course);
	}
	if (_professors.size() != _courses.size())
		throw (runtime_error("Not enough professors or courses"));
	uint	i = 0;
	for (auto course: _courses)
		_headmaster.assignProfessorToCourse(_professors.at(i++), course);
}

void	School::requestRingBell(void){
	for (auto observer: _observers)
		_headmaster.executeEvent(observer, Event::RingBell);
}

void	School::addCourse(Course* course){
	if (find(_courses.begin(), _courses.end(), course) == _courses.end())
		_courses.push_back(course);
}

void	School::addObserver(Observer* observer){
	if (find(_observers.begin(), _observers.end(), observer) == _observers.end())
		_observers.push_back(observer);
}

void	School::recruteProfessor(Professor* professor){
	if (find(_professors.begin(), _professors.end(), professor) == _professors.end())
		_professors.push_back(professor);
}

void	School::recruteStudent(Student* student){
	if (find(_students.begin(), _students.end(), student) == _students.end())
		_students.push_back(student);
}

void	School::graduationCeremony(void){
	for (auto course: _courses){
		for (auto student: course->getStudent())
			course->getResponsable()->graduateStudent(&_headmaster, student, course);
	}
}

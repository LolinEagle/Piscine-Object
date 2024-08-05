#include <Course.hpp>
#include <Person.hpp>

// Try to not call this one but assign(Professor*, Headmaster*)
void	Course::assign(Professor* professor){
	_responsable = professor;
}

void	Course::assign(Professor* professor, Headmaster* headmaster){
	_responsable = professor;
	professor->assignCourse(this, headmaster);
}

void	Course::subscribe(Student* student){
	if (find(_students.begin(), _students.end(), student) == _students.end()){
		_students.push_back(student);
		student->subscribedCourse(this);
	}
}

void	Course::unSubscribe(Student* student){
	auto it = find(_students.begin(), _students.end(), student);
	if (it != _students.end())
		_students.erase(it);
}

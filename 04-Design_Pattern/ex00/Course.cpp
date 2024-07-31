#include <Course.hpp>
#include <Person.hpp>

void	Course::subscribe(Student* student){
	if (find(_students.begin(), _students.end(), student) == _students.end()){
		_students.push_back(student);
		student->subscribedCourse(this);
	}
}

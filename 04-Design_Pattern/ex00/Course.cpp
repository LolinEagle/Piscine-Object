#include <Course.hpp>

void	Course::subscribe(Student* student){
	if (find(_students.begin(), _students.end(), student) == _students.end())
		_students.push_back(student);
}

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

void	Observer::executeEvent(Event event, Headmaster* headmaster){
	if (event == Event::RingBell){
		if (!_course || !headmaster)
			return ;
		static bool ringBell = false;
		if (ringBell == false){
			_professor = _course->getResponsable();
			_students = _course->getStudent();
			_professor->closeCourse();
			for (auto students: _students)
				students->exitClass(_course);
			ringBell = true;
		} else {
			_course->assign(_professor, headmaster);
			for (auto students: _students)
				_course->subscribe(students);
			ringBell = false;
		}
	}
}

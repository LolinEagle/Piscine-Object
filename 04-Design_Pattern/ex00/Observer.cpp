#include <Observer.hpp>

void	Observer::executeEvent(Event event, Headmaster* headmaster){
	if (event == Event::RingBell){
		if (!_course || !headmaster)
			return ;
		if (_ringBell == false){
			_professor = _course->getResponsable();
			_students = _course->getStudent();
			_professor->closeCourse();
			for (auto students: _students)
				students->exitClass(_course);
			_ringBell = true;
		} else {
			_course->assign(_professor, headmaster);
			for (auto students: _students)
				_course->subscribe(students);
			_ringBell = false;
		}
	}
}

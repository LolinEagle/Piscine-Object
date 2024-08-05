#include <Form.hpp>

ostream&	operator<<(ostream& os, const Form& form){
	switch (form._formType){
		case FormType::CourseFinished:
			os << "CourseFinished";
		case FormType::NeedMoreClassRoom:
			os << "NeedMoreClassRoom";
		case FormType::NeedCourseCreation:
			os << "NeedCourseCreation";
		case FormType::SubscriptionToCourse:
			os << "SubscriptionToCourse";
		case FormType::GraduateStudent:
			os << "GraduateStudent";
		case FormType::StudentJoinCouse:
			os << "StudentJoinCouse";
	}
	return (os);
}

void	CourseFinishedForm::execute(void){
	cout << "Course finished" << endl;
	delete (_course);
	_course = NULL;
}

void	NeedMoreClassRoomForm::execute(void){
	cout << "Need more class room" << endl;
	_classroom = new Classroom();
}

void	NeedCourseCreationForm::execute(void){
	cout << "Need course creation" << endl;
	_course = new Course(_name);
}

void	SubscriptionToCourseForm::execute(void){
	if (!_professor || !_course)
		return ;
	if (_professor->getCurrentCourse()) 
		_professor->getCurrentCourse()->assign(NULL);
	_professor->setCurrentCourse(_course);// You're now assigned to this course.
	_course->assign(_professor);
}

void	GraduateStudentForm::execute(void){
	cout << "Graduate " << _student->getName() << " for " << _course->getName() << endl;
	if (_student && _course){
		_student->graduate(_course);
		_student->exitClass(_course);// Leave course
	}
}

void	StudentJoinCouseForm::execute(void){
	if (_student && _course)
		_course->subscribe(_student);
}

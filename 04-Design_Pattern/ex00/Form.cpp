#include <Form.hpp>

ostream&	operator<<(ostream& os, const Form& form){
	if (form._formType == FormType::CourseFinished)
		os << "CourseFinished";
	else if (form._formType == FormType::NeedMoreClassRoom)
		os << "NeedMoreClassRoom";
	else if (form._formType == FormType::NeedCourseCreation)
		os << "NeedCourseCreation";
	else if (form._formType == FormType::SubscriptionToCourse)
		os << "SubscriptionToCourse";
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
	cout << "Graduate student" << endl;
	if (_student && _course){
		_student->graduate(_course);
		_student->exitClass(_course);// Leave course
	}
}

void	StudentJoinCouseForm::execute(void){
	if (_student && _course)
		_course->subscribe(_student);
}

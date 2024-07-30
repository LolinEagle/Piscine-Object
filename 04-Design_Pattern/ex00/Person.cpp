#include <Person.hpp>

void	Staff::sign(Form* form){
	form->setSigned();
}

void	Headmaster::receiveForm(Form* form){
	if (find(_formToValidate.begin(), _formToValidate.end(), form) == _formToValidate.end())
		if (form->getSigned() == false) _formToValidate.push_back(form);
}

void	Headmaster::executeForm(void){
	for (auto form: _formToValidate){
		form->execute();
		form->setSigned();
	}
}

void	Headmaster::assignProfessorToCourse(Professor* professor, Course* course){
	if (!professor)
		return ;
	professor->assignCourse(course);
}

GraduateStudentForm*	Headmaster::receiveGraduateStudentForm(void){
	if (!_secretary)
		return (NULL);
	// Headmaster to Secretary : I need a form for graduation
	// Secretary to Headmaster : Here, take this form
	// Headmaster to Professor : Can you fill this form ?
	return (dynamic_cast<GraduateStudentForm*>(
		_secretary->createForm(FormType::GraduateStudent)
	));
}

void	Headmaster::confirmGraduation(GraduateStudentForm* form){
	// [Sign form and execute the graduation]
	form->setSigned();
	form->execute();
	delete (form);
}

Form*	Secretary::createForm(FormType formType){
	Form*	form;

	if (formType == FormType::CourseFinished)
		form = new CourseFinishedForm();
	else if (formType == FormType::NeedMoreClassRoom)
		form = new NeedMoreClassRoomForm();
	else if (formType == FormType::NeedCourseCreation)
		form = new NeedCourseCreationForm();
	else if (formType == FormType::SubscriptionToCourse)
		form = new SubscriptionToCourseForm();
	else if (formType == FormType::GraduateStudent)
		form = new GraduateStudentForm();
	else
		return (NULL);
	return (form);
}

void	Professor::assignCourse(Course* course){
	if (!course)
		return ;
	if (_currentCourse)
		_currentCourse->assign(NULL);
	_currentCourse = course;
	course->assign(this);
}

void	Professor::doClass(void){
	if (!_currentCourse)
		return ;
	cout << _name << " teach course of " << _currentCourse->getName() << endl;
}

void	Professor::closeCourse(void){
	if (_currentCourse)
		delete (_currentCourse);
}

void	Professor::graduateStudent(Headmaster* headmaster, Student* student, Course* course){
	if (!headmaster || !student)
		return ;
	GraduateStudentForm* form = headmaster->receiveGraduateStudentForm();
	// [Write down information]
	form->setCourse(course);
	form->setStudent(student);
	// Can you confirm this graduation ?
	headmaster->confirmGraduation(form);
}

#include <Person.hpp>

void	Staff::sign(Form* form){
	form->setSigned();
}

void	Student::attendClass(Classroom* classroom){
	if (!classroom || !classroom->getCurrentRoom())
		return ;
	if (find(_subscribedCourse.begin(), _subscribedCourse.end(), classroom->getCurrentRoom()) == _subscribedCourse.end())
		_subscribedCourse.push_back(classroom->getCurrentRoom());
}

void	Student::exitClass(Course* course){
	// Leave course
	vector<Course*>::iterator it = find(_subscribedCourse.begin(), _subscribedCourse.end(), course);
	if (it != _subscribedCourse.end())
		_subscribedCourse.erase(it);
}

void	Student::subscribedCourse(Course* course){
	if (find(_subscribedCourse.begin(), _subscribedCourse.end(), course) == _subscribedCourse.end())
		_subscribedCourse.push_back(course);
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
	professor->assignCourse(course, this);
}

void	Headmaster::assignStudentToCourse(Student* student, Course* course){
	if (!student || !course)
		return ;
	course->subscribe(student);
}

SubscriptionToCourseForm*	Headmaster::receiveSubscriptionToCourseForm(void){
	if (!_secretary)
		return (NULL);
	// Headmaster to Secretary : Can i get a new course form ?
	// Secretary to Headmaster : Here, take this form
	// Headmaster to Professor : You need to fill this form
	return (dynamic_cast<SubscriptionToCourseForm*>(
		_secretary->createForm(FormType::SubscriptionToCourse)
	));
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

void	Headmaster::confirmAssignCourse(SubscriptionToCourseForm* form){
	// [Sign form and execute the course creation]
	form->setSigned();
	form->execute();
	delete (form);
}

void	Headmaster::confirmGraduation(GraduateStudentForm* form){
	// [Sign form and execute the graduation]
	form->setSigned();
	form->execute();// Congratulation, you're graduate you can leave this course
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

void	Professor::assignCourse(Course* course, Headmaster* headmaster){
	if (!course || !headmaster)
		return ;
	SubscriptionToCourseForm*	form = headmaster->receiveSubscriptionToCourseForm();
	if (!form)
		return ;
	// [Write down information]
	form->setCourse(course);
	form->setProfessor(this);
	// Can you confirm the creation of this course ?
	headmaster->confirmAssignCourse(form);
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
	if (!form)
		return ;
	// [Write down information]
	form->setCourse(course);
	form->setStudent(student);
	// Can you confirm this graduation ?
	headmaster->confirmGraduation(form);
}

void	Professor::learnStudent(Student* student, string str){
	if (student)
		student->learn(str);
}

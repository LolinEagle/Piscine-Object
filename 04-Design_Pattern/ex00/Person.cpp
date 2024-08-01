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

void	Student::lookForNewCourse(Headmaster* headmaster, Course* course){
	if (!headmaster)
		return ;
	// Hello, i want a form to join a course
	StudentJoinCouseForm* form = headmaster->receiveStudentJoinCouseForm();
	if (!form)
		return ;
	// [Write down information]
	form->setCourse(course);
	form->setStudent(this);
	// Can you confirm the course subscription ?
	headmaster->confirmCourseSubscription(form);
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

StudentJoinCouseForm*	Headmaster::receiveStudentJoinCouseForm(void){
	if (!_secretary)
		return (NULL);
	// Headmaster to Secretary : Can i get a join course form ?
	// Secretary to Headmaster : Take this form
	// Headmaster to Professor : You need to fill this form.
	return (dynamic_cast<StudentJoinCouseForm*>(
		_secretary->createForm(FormType::StudentJoinCouse)
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

void	Headmaster::confirmCourseSubscription(StudentJoinCouseForm* form){
	// [Sign form and execute the course subscription]
	form->setSigned();
	form->execute();// It's done, you can attend your class now
	delete (form);
}

Classroom*	Headmaster::getNewClassroom(void){
	if (!_secretary)
		return (NULL);
	NeedMoreClassRoomForm*	form = dynamic_cast<NeedMoreClassRoomForm*>(_secretary->createForm(FormType::NeedMoreClassRoom));
	form->setSigned();
	form->execute();
	Classroom*	classroom = form->getClassroom();
	delete (form);
	return (classroom);
}

Form*	Secretary::createForm(FormType formType){
	Form*	form;

	switch (formType){
		case FormType::CourseFinished:
			form = new CourseFinishedForm(); break;
		case FormType::NeedMoreClassRoom:
			form = new NeedMoreClassRoomForm(); break;
		case FormType::NeedCourseCreation:
			form = new NeedCourseCreationForm(); break;
		case FormType::SubscriptionToCourse:
			form = new SubscriptionToCourseForm(); break;
		case FormType::GraduateStudent:
			form = new GraduateStudentForm(); break;
		case FormType::StudentJoinCouse:
			form = new StudentJoinCouseForm(); break;
		default:
			return (NULL);
	}
	return (form);
}

Professor::~Professor(){
	if (_classroom)
		delete (_classroom);
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

void	Professor::doClass(Headmaster* headmaster){
	if (!_currentCourse || !headmaster)
		return ;
	if (!_classroom){
		_classroom = headmaster->getNewClassroom();
		_classroom->assignCourse(_currentCourse);
	}
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
	// [Take note]
	if (student)
		student->learn(str);
}

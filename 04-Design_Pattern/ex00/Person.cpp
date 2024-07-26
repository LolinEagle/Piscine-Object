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
	else
		return (NULL);
	return (form);
}

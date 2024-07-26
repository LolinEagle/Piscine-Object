#include <Person.hpp>

void	Headmaster::receiveForm(Form* form){
	if (find(_formToValidate.begin(), _formToValidate.end(), form) == _formToValidate.end())
		_formToValidate.push_back(form);
}

Form*	Secretary::createForm(FormType formType){
	Form*	form = NULL;

	if (formType == FormType::CourseFinished)
		*form = CourseFinishedForm();
	else if (formType == FormType::NeedMoreClassRoom)
		*form = NeedMoreClassRoomForm();
	else if (formType == FormType::NeedCourseCreation)
		*form = NeedCourseCreationForm();
	else if (formType == FormType::SubscriptionToCourse)
		*form = SubscriptionToCourseForm();
	return (form);
}

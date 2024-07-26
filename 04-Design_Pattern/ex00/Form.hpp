#pragma once

#include <Datas.hpp>

enum class FormType{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form{
private:
	FormType	_formType;
public:
	Form(FormType formType): _formType(formType){}

	friend ostream&	operator<<(ostream& os, const Form& form);

	virtual void	execute(void) = 0;
	FormType		getFormType(void){return(_formType);}
};

class CourseFinishedForm: public Form{
public:
	CourseFinishedForm(void): Form(FormType::CourseFinished){}

	void	execute(void){cout << "CourseFinishedForm" << endl;}
};

class NeedMoreClassRoomForm: public Form{
public:
	NeedMoreClassRoomForm(void): Form(FormType::NeedMoreClassRoom){}

	void	execute(void){cout << "NeedMoreClassRoomForm" << endl;}
};

class NeedCourseCreationForm: public Form{
public:
	NeedCourseCreationForm(void): Form(FormType::NeedCourseCreation){}

	void	execute(void){cout << "NeedCourseCreationForm" << endl;}
};

class SubscriptionToCourseForm: public Form{
public:
	SubscriptionToCourseForm(void): Form(FormType::SubscriptionToCourse){}

	void	execute(void){cout << "SubscriptionToCourseForm" << endl;}
};

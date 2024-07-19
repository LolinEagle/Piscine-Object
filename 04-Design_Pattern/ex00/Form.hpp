#pragma once

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
	Form(FormType p_formType): _formType(p_formType){}

	virtual void	execute() = 0;
	FormType		getFormType(void){return(_formType);}
};

class CourseFinishedForm : public Form{
public:
	CourseFinishedForm(void): Form(FormType::CourseFinished){}

	void	execute(void){}
};

class NeedMoreClassRoomForm : public Form{
public:
	NeedMoreClassRoomForm(void): Form(FormType::NeedMoreClassRoom){}

	void	execute(void){}
};

class NeedCourseCreationForm : public Form{
public:
	NeedCourseCreationForm(void): Form(FormType::NeedCourseCreation){}

	void	execute(void){}
};

class SubscriptionToCourseForm : public Form{
public:
	SubscriptionToCourseForm(void): Form(FormType::SubscriptionToCourse){}

	void	execute(void){}
};

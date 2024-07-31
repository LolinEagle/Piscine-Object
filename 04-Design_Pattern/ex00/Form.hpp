#pragma once

#include <Course.hpp>
#include <Room.hpp>

enum class FormType{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse,
	GraduateStudent,
};

class Course;
class Classroom;

class Form{
protected:
	FormType	_formType;
	bool		_signed;
public:
	Form(FormType formType): _formType(formType), _signed(false){}
	virtual ~Form(){};

	friend ostream&	operator<<(ostream& os, const Form& form);

	virtual void	execute(void) = 0;
	FormType		getFormType(void) const {return(_formType);}
	bool			getSigned(void) const {return(_signed);}
	void			setSigned(void){_signed = true;}
};

class CourseFinishedForm: public Form{
private:
	Course*	_course;
public:
	CourseFinishedForm(void): Form(FormType::CourseFinished), _course(NULL){}

	void	setCourse(Course* course){_course = course;}
	void	execute(void);
};

class NeedMoreClassRoomForm: public Form{
private:
	Classroom*	_classroom;
public:
	NeedMoreClassRoomForm(void): Form(FormType::NeedMoreClassRoom), _classroom(NULL){}

	Classroom*	getClassroom(void){return (_classroom);}
	void		execute(void);
};

class NeedCourseCreationForm: public Form{
private:
	string	_name;
	Course*	_course;
public:
	NeedCourseCreationForm(void): Form(FormType::NeedCourseCreation), _course(NULL){}

	Course*	getCourse(void){return (_course);}
	void	setName(string name){_name = name;}
	void	execute(void);
};

class SubscriptionToCourseForm: public Form{
private:
	Course*		_course;
	Professor*	_professor;
public:
	SubscriptionToCourseForm(void):
	Form(FormType::SubscriptionToCourse), _course(NULL), _professor(NULL){}

	void	setCourse(Course* course){_course = course;}
	void	setProfessor(Professor* professor){_professor = professor;}
	void	execute(void);
};

class GraduateStudentForm: public Form{
private:
	Course*		_course;
	Student*	_student;
public:
	GraduateStudentForm(void): Form(FormType::GraduateStudent), _course(NULL), _student(NULL){}

	void	setCourse(Course* course){_course = course;}
	void	setStudent(Student* student){_student = student;}
	Course*	getCourse(void){return (_course);}
	void	execute(void);
};

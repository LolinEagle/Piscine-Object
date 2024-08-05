#include <Person.hpp>

int	main(void){
	Secretary	secretary("Secretary");
	Headmaster	headmaster("Headmaster");

	Form*	courseFinished = secretary.createForm(FormType::CourseFinished);
	Form*	needMoreClassRoom = secretary.createForm(FormType::NeedMoreClassRoom);
	Form*	needCourseCreation = secretary.createForm(FormType::NeedCourseCreation);
	Form*	subscriptionToCourse = secretary.createForm(FormType::SubscriptionToCourse);

	headmaster.receiveForm(courseFinished);
	headmaster.receiveForm(needMoreClassRoom);
	headmaster.receiveForm(needCourseCreation);
	headmaster.receiveForm(subscriptionToCourse);
	cout << headmaster.getFormToValidate().size() << endl;

	Course*		course = new Course("Course");
	Professor*	professor = new Professor("Professor");

	CourseFinishedForm*			a = static_cast<CourseFinishedForm*>(courseFinished);
	NeedMoreClassRoomForm*		b = static_cast<NeedMoreClassRoomForm*>(needMoreClassRoom);
	NeedCourseCreationForm*		c = static_cast<NeedCourseCreationForm*>(needCourseCreation);
	SubscriptionToCourseForm*	d = static_cast<SubscriptionToCourseForm*>(subscriptionToCourse);

	d->setCourse(course);
	d->setProfessor(professor);
	headmaster.executeForm();

	a->setCourse(course);
	a->execute();
	delete (professor);
	delete (b->getClassroom());
	delete (c->getCourse());

	delete (courseFinished);
	delete (needMoreClassRoom);
	delete (needCourseCreation);
	delete (subscriptionToCourse);
	return (0);
}

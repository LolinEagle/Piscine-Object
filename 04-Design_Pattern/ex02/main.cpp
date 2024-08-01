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

	CourseFinishedForm*			courseFinishedForm = dynamic_cast<CourseFinishedForm*>(courseFinished);
	NeedMoreClassRoomForm*		needMoreClassRoomForm = dynamic_cast<NeedMoreClassRoomForm*>(needMoreClassRoom);
	NeedCourseCreationForm*		needCourseCreationForm = dynamic_cast<NeedCourseCreationForm*>(needCourseCreation);
	SubscriptionToCourseForm*	subscriptionToCourseForm = dynamic_cast<SubscriptionToCourseForm*>(subscriptionToCourse);

	subscriptionToCourseForm->setCourse(course);
	subscriptionToCourseForm->setProfessor(professor);
	headmaster.executeForm();

	courseFinishedForm->setCourse(course);
	courseFinishedForm->execute();
	delete (professor);
	delete (needMoreClassRoomForm->getClassroom());
	delete (needCourseCreationForm->getCourse());

	delete (courseFinished);
	delete (needMoreClassRoom);
	delete (needCourseCreation);
	delete (subscriptionToCourse);
	return (0);
}

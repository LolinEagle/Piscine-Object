#include <Course.hpp>
#include <Person.hpp>
#include <Person.hpp>

size_t ftSize(Student& student){
	return (student.getSubscribedCourse().size());
}

int	main(void){
	Headmaster	headmaster("Headmaster");
	Secretary	secretary("Secretary");
	Course		course("Course");
	Professor	professor("Professor");
	Student		student1("Student1");
	Student		student2("Student2");
	Student		student3("Student3");
	Observer	observer(&course);

	headmaster.setSecretary(&secretary);
	course.assign(&professor, &headmaster);
	course.subscribe(&student1);
	course.subscribe(&student2);
	course.subscribe(&student3);
	cout << "Should be 1: " << (course.getResponsable() != NULL) << endl;
	cout << "Should be 3: " << course.getStudent().size() << endl;
	cout << "Should be 1: " << (professor.getCurrentCourse() != NULL) << endl;
	cout << "Should be 3: " << ftSize(student1) + ftSize(student2) + ftSize(student3) << endl;
	headmaster.executeEvent(&observer, Event::RingBell);
	cout << "\nShould be 0: " << (course.getResponsable() != NULL) << endl;
	cout << "Should be 0: " << course.getStudent().size() << endl;
	cout << "Should be 0: " << (professor.getCurrentCourse() != NULL) << endl;
	cout << "Should be 0: " << ftSize(student1) + ftSize(student2) + ftSize(student3) << endl;
	headmaster.executeEvent(&observer, Event::RingBell);
	cout << "\nShould be 1: " << (course.getResponsable() != NULL) << endl;
	cout << "Should be 3: " << course.getStudent().size() << endl;
	cout << "Should be 1: " << (professor.getCurrentCourse() != NULL) << endl;
	cout << "Should be 3: " << ftSize(student1) + ftSize(student2) + ftSize(student3) << endl;
	return (0);
}

#include <Course.hpp>
#include <Person.hpp>

int	main(void){
	Headmaster	headmaster("Headmaster");
	Secretary	secretary("Secretary");
	Professor	professor("Professor");
	Professor	professor2("Professor2");
	Student		student1("Student1");
	Student		student2("Student2");
	Student		student3("Student3");
	Course		course("Course");
	Classroom	classroom(&course);

	headmaster.setSecretary(&secretary);
	// Attend your classes
	headmaster.assignProfessorToCourse(&professor, &course);
	cout << "Should be true (1): " << (&professor == course.getResponsable()) << endl;
	// Teach course
	professor.doClass(&headmaster);
	// I have a student who need to graduate. Can i have a form ?
	professor.graduateStudent(&headmaster, &student1, &course);
	cout << "Should be 1: " << course.getNumberOfClassToGraduate() << endl;
	// Follow class
	student1.attendClass(&classroom);
	cout << "Should be 1: " << student1.getSubscribedCourse().size() << endl;
	// I have no course to attend.
	professor2.assignCourse(&course, &headmaster);
	cout << "Should not be null: " << professor2.getCurrentCourse() << endl;
	// Teach course
	professor2.doClass(&headmaster);

	// Part 2

	// Attend your classes
	headmaster.assignStudentToCourse(&student2, &course);
	cout << "Should be 1: " << student2.getSubscribedCourse().size() << endl;
	// Learn this
	professor.learnStudent(&student2, "C++ is hard");
	// [emit the graduate form]
	professor2.graduateStudent(&headmaster, &student2, &course);
	cout << "Should be 0: " << student2.getSubscribedCourse().size() << endl;
	// Will look out for new things to learn
	student2.learn("python is easy");
	// [Look for a course to follow]
	student3.lookForNewCourse(&headmaster, &course);
	cout << "Should be 1: " << student3.getSubscribedCourse().size() << endl;
	return (0);
}

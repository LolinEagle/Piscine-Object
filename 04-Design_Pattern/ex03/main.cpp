#include <Course.hpp>
#include <Person.hpp>

int	main(void){
	Headmaster	headmaster("Headmaster");
	Secretary	secretary("Secretary");
	Professor	professor("Professor");
	Professor	professor2("Professor2");
	Student		student("Student");
	Student		student2("Student2");
	Course		course("Course");
	Classroom	classroom(&course);

	headmaster.setSecretary(&secretary);

	// Attend your classes
	headmaster.assignProfessorToCourse(&professor, &course);
	cout << "Should be true (1): " << (&professor == course.getResponsable()) << endl;

	// Teach course
	professor.doClass();

	// I have a student who need to graduate. Can i have a form ?
	professor.graduateStudent(&headmaster, &student, &course);
	cout << "Should be 1: " << course.getNumberOfClassToGraduate() << endl;

	// Follow class
	student.attendClass(&classroom);
	cout << "Should be 1: " << student.getSubscribedCourse().size() << endl;

	// I have no course to attend.
	professor2.assignCourse(&course, &headmaster);
	cout << "Should not be null: " << professor2.getCurrentCourse() << endl;

	// Teach course
	professor2.doClass();

	// Part 2

	// Attend your classes
	headmaster.assignStudentToCourse(&student2, &course);
	cout << "Should be 1: " << student2.getSubscribedCourse().size() << endl;

	// Learn this
	professor.learnStudent(&student, "C++ is hard");

	// [emit the graduate form]
	professor2.graduateStudent(&headmaster, &student2, &course);
	cout << "Should be 0: " << student2.getSubscribedCourse().size() << endl;

	// Will look out for new things to learn
	// [Look for a course to follow]

	// Hello, i want a form to join a couse


	return (0);
}

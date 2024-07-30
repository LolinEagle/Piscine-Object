#include <Course.hpp>
#include <Person.hpp>

int	main(void){
	Headmaster	headmaster("Headmaster");
	Secretary	secretary("Secretary");
	Professor	professor("Professor");
	Student		student("Student");
	Course		course("Course");

	// Attend your classes
	headmaster.assignProfessorToCourse(&professor, &course);
	cout << "Should be true (1): " << (&professor == course.getResponsable()) << endl;

	// Teach course
	professor.doClass();

	headmaster.setSecretary(&secretary);
	// I have a student who need to graduate. Can i have a form ?
	cout << "Should be 0: " << course.getNumberOfClassToGraduate() << endl;
	professor.graduateStudent(&headmaster, &student, &course);
	cout << "Should be 1: " << course.getNumberOfClassToGraduate() << endl;
	return (0);
}

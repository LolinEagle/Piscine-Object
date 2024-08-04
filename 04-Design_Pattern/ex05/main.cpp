#include <School.hpp>

int	getGraduate(School&	school, string course){
	return (school.getCourse(course)->getNumberOfClassToGraduate());
}

int	main(void){
	School		school;
	Course		course1("course1"), course2("course2"), course3("course3");
	Observer	observer1(&course1), observer2(&course2), observer3(&course3);
	Professor	professor1("professor1"), professor2("professor2"), professor3("professor3");
	Student		student1("student1"), student2("student2"), student3("student3");

	school.addCourse(&course1);
	school.addCourse(&course2);
	school.addCourse(&course3);
	school.addObserver(&observer1);
	school.addObserver(&observer2);
	school.addObserver(&observer3);
	school.recruteStudent(&student1);
	school.recruteStudent(&student2);
	school.recruteStudent(&student3);
	school.recruteProfessor(&professor1);
	school.recruteProfessor(&professor2);
	school.recruteProfessor(&professor3);

	cout << "Number of courses: " << school.getAllCourses().size() << endl;
	cout << "Number of students: " << school.getStudents().size() << endl;
	cout << "Number of professors: " << school.getProfessors().size() << endl;
	school.runDayRoutine();
	cout << "Course 1 student number: " << school.getCourse("course1")->getStudent().size() << endl;
	cout << "Course 2 student number: " << school.getCourse("course2")->getStudent().size() << endl;
	cout << "Course 3 student number: " << school.getCourse("course3")->getStudent().size() << endl;
	school.graduationCeremony();
	cout << "Course 1 number of class to graduate: " << getGraduate(school, "course1") << endl;
	cout << "Course 2 number of class to graduate: " << getGraduate(school, "course2") << endl;
	cout << "Course 3 number of class to graduate: " << getGraduate(school, "course3") << endl;
	return (0);
}

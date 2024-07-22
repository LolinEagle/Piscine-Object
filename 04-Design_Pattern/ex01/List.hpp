#include <Singetons.hpp>

class StudentList: public Singetons<Student>{
public:
	StudentList(void){}
	~StudentList(){}
};



// StaffList, holding every staff existing in the school.
// • CourseList, holding every course currently running in the school.
// • RoomList, holding every room existing in the school

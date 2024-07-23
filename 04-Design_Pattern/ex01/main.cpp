#include <List.hpp>

int	main(void){
	StudentList*	a = StudentList::getInstance();
	StaffList*		b = StaffList::getInstance();
	CourseList*		c = CourseList::getInstance();
	RoomList*		d = RoomList::getInstance();
	StudentList*	a2 = StudentList::getInstance();
	StaffList*		b2 = StaffList::getInstance();
	CourseList*		c2 = CourseList::getInstance();
	RoomList*		d2 = RoomList::getInstance();

	cout << (a == a2) << ' ' << (b == b2) << ' ' << (c == c2) << ' ' << (d == d2) << ' ' <<
			(static_cast<void*>(a) != static_cast<void*>(b)) << ' ' <<
			(static_cast<void*>(a) != static_cast<void*>(c)) << ' ' <<
			(static_cast<void*>(a) != static_cast<void*>(d)) << ' ' <<
			(static_cast<void*>(b) != static_cast<void*>(c)) << ' ' <<
			(static_cast<void*>(b) != static_cast<void*>(d)) << ' ' <<
			(static_cast<void*>(c) != static_cast<void*>(d)) << endl;

	// Student	nfelsemb("nfelsemb");
	// Student	frrusso;
	// Student	sle-huec;

	delete (a);
	delete (b);
	delete (c);
	delete (d);
	return (0);
}

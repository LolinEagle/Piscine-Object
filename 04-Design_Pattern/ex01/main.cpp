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

	Student	frrusso("frrusso");
	Student	mriant("mriant");
	Student	nfelsemb("nfelsemb");
	Student	sle_huec("sle-huec");
	a->addList(&frrusso);
	a->addList(&mriant);
	a->addList(&nfelsemb);
	a->addList(&sle_huec);

	Headmaster	s1("1");
	Secretary	s2("2");
	Professor	s3("3");
	b->addList(&s1);
	b->addList(&s2);
	b->addList(&s3);

	Course	computerScience("Computer science");
	c->addList(&computerScience);

	Classroom			r1;
	SecretarialOffice	r2;
	HeadmasterOffice	r3;
	StaffRestRoom		r4;
	Courtyard			r5;
	d->addList(&r1);
	d->addList(&r2);
	d->addList(&r3);
	d->addList(&r4);
	d->addList(&r5);

	cout << "Should be 4:" << a->getList().size() << endl;
	cout << "Should be 3:" << b->getList().size() << endl;
	cout << "Should be 1:" << c->getList().size() << endl;
	cout << "Should be 5:" << d->getList().size() << endl;
	a->removeList(&sle_huec);
	cout << "Should be 3:" << a->getList().size() << endl;
	delete (a);
	delete (b);
	delete (c);
	delete (d);
	return (0);
}

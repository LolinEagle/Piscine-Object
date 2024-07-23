#pragma once

#include <Singetons.hpp>

class StudentList: public Singetons<Student, StudentList>{
};

class StaffList: public Singetons<Staff, StaffList>{
};

class CourseList: public Singetons<Course, CourseList>{
};

class RoomList: public Singetons<Room, RoomList>{
};

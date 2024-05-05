#include "../../include/dto/ClassDTO.hpp"
#include <vector>
#include <memory>

ClassDTO::~ClassDTO(){}

void ClassDTO::setTeacher(string teacher){this->teacher=teacher;}
string ClassDTO::getTeacher(){return teacher;}

vector<string>& ClassDTO::getClassroomStudents() 
{
	return classroomStudents;
}

void ClassDTO::setClassroomStudents(vector<string> & _classroomStudents) {
	classroomStudents = _classroomStudents;
}
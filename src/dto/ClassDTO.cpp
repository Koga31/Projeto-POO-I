#include "../../include/dto/ClassDTO.hpp"
#include <vector>
#include <memory>

ClassDTO::~ClassDTO(){}

void ClassDTO::setTeacher(string teacher){this->teacher=teacher;}
string ClassDTO::getTeacher(){return teacher;}

void ClassDTO::setClassGradesStudents(const map<string, float>& classroomStudents){
	this->classGradesStudents = classroomStudents;
}

map<string, float>& ClassDTO::getClassGradesStudents(){return classGradesStudents;}

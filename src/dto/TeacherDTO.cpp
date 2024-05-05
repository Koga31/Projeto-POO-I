#include "../../include/dto/TeacherDTO.hpp"

TeacherDTO::~TeacherDTO(){}

void TeacherDTO::setId(string id){this->id=id;}
void TeacherDTO::setSalary(float salary){this->salary=salary;}
void TeacherDTO::setSubjects(map<string,shared_ptr<Subject>> subjects){this->subjects=subjects;}

string TeacherDTO::getId(){return id;}
float TeacherDTO::getSalary(){return salary;}
map<string, shared_ptr<Subject>>& TeacherDTO::getSubjects(){return subjects;}
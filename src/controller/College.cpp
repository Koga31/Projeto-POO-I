#include "../../include/controller/College.hpp"

map<string, shared_ptr<Person>> College::students;
map<string, shared_ptr<Person>> College::teachers;
vector<shared_ptr<ClassDTO>> College::subjects;


map<string, shared_ptr<Person>> & College::getStudents() {
	return students;
}

void College::setStudents(map<string, shared_ptr<Person>> &_students) 
{
	students = _students;
}

map<string, shared_ptr<Person>> & College::getTeachers() 
{
	return teachers;
}

void College::setTeachers(map<string, shared_ptr<Person>> &_teachers) 
{
	teachers = _teachers;
}

vector<shared_ptr<ClassDTO>> & College::getSubjects() 
{
	return subjects;
}

void College::setSubjects(vector<shared_ptr<ClassDTO>> &_subjects) {
	subjects = _subjects;
}
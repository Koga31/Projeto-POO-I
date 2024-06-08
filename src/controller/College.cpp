#include "../../include/controller/College.hpp"
#include <algorithm>

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

bool College::doesNotHaveStudent(const string &ra){
	return (students.find(ra) == students.end());
}

bool College::doesNotHaveTeacher(const string &id){
	return (teachers.find(id) == teachers.end());
}

bool College::doesNotHaveClass(const string &code, const int &year, const int &semester){
	return (find_if(College::getSubjects().begin(), College::getSubjects().end(), [&code, &year, &semester](shared_ptr<ClassDTO> classObj){
			return((classObj->getCode() == code) && (classObj->getYear() == year) && (classObj->getSemesterNumber() == semester));
		}
	) == College::getSubjects().end());
}
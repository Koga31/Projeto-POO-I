#ifndef INCLUDE_CONTROLLER_COLLEGE_HPP
#define INCLUDE_CONTROLLER_COLLEGE_HPP

#include <vector>
#include <map>
#include <memory>

#include "../../include/dto/Person.hpp"
#include "../../include/dto/ClassDTO.hpp"

using namespace std;

class College final 
{
private:
	static map<string, shared_ptr<Person>> students;
	static map<string, shared_ptr<Person>> teachers;
	static vector<shared_ptr<ClassDTO>> subjects;
	

public:
	static map<string,shared_ptr<Person>> & getStudents();
	static void setStudents(map<string, shared_ptr<Person>> &students);
	static map<string, shared_ptr<Person>> & getTeachers();
	static void setTeachers(map<string, shared_ptr<Person>> &teachers);
	static vector<shared_ptr<ClassDTO>> & getSubjects();
	static void setSubjects(vector<shared_ptr<ClassDTO>> &subject);
};

#endif
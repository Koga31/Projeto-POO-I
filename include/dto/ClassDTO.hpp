#ifndef CLASSDTO_HPP
#define CLASSDTO_HPP
#include "../database/Semester.hpp"
#include "../database/Subject.hpp"
#include "Person.hpp"
#include "StudentDTO.hpp"
#include <memory>
#include <vector>

class ClassDTO : public Semester, public Subject 
{
    private:
        string teacher;
        vector<string> classroomStudents;
        
    public:
        ClassDTO(string _code="", string _name="", string _description="", int year=0, int semesterNumber=0): Subject(_code, _name, _description), Semester(year, semesterNumber){}
        virtual ~ClassDTO();
        void setTeacher(string teacher);
        string getTeacher();
        void setClassroomStudents(vector<string>& classroomStudents);
        vector<string>& getClassroomStudents();
};

#endif
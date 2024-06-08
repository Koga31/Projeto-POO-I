#ifndef CLASSDTO_HPP
#define CLASSDTO_HPP
#include "../database/Semester.hpp"
#include "../database/Subject.hpp"
#include "Person.hpp"
#include "StudentDTO.hpp"
#include <memory>
#include <vector>
#include <map>

class ClassDTO : public Semester, public Subject 
{
    private:
        string teacher;
        map<string, float> classGradesStudents;
        
    public:
        ClassDTO(string code="", string name="", string description="", int year=0, int semesterNumber=0): Subject(code, name, description), Semester(year, semesterNumber){}
        virtual ~ClassDTO();
        void setTeacher(string teacher);
        string getTeacher();
        void setClassGradesStudents(const map<string, float>& classGradesStudents);
        map<string, float>& getClassGradesStudents();
};

#endif
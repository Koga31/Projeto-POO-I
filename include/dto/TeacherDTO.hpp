#ifndef TEACHERDTO_HPP
#define TEACHERDTO_HPP
#include "Person.hpp"
#include "../database/Subject.hpp"
#include <map>
#include <memory>

class TeacherDTO : public Person {
    private:
        string id;
        float salary;
    public:
        TeacherDTO(string _name="", int _age=0, string _phone ="", string _id="", float _salary=0):Person(_name, _age, _phone), id(_id), salary(_salary){}
        virtual ~TeacherDTO();
        void setId(string id);
        void setSalary(float salary);
        string getId() const;
        float getSalary() const;
        
        void printInfo();
        string getIdentifier();
};

#endif
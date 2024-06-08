/*Representa uma disciplina. Uma matéria possui um código, um nome e uma
ementa. */


#ifndef SUBJECT_HPP
#define SUBJECT_HPP
#include <iostream>
using namespace std;

class Subject
{

private:
    string code;
    string name;
    string description;

public:
    Subject(string _code, string _name, string _description):code(_code),name(_name),description(_description){}
    virtual ~Subject();
    void setCode(string code);
    void setName(string name);
    void setDescription(string description);
    string  getCode();
    string  getName();
    string  getDescription();

};

#endif
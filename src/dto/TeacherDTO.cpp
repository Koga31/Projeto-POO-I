#include "../../include/dto/TeacherDTO.hpp"

TeacherDTO::~TeacherDTO(){}

void TeacherDTO::setId(string id){this->id=id;}
void TeacherDTO::setSalary(float salary){this->salary=salary;}

string TeacherDTO::getId() const {return id;}
float TeacherDTO::getSalary() const {return salary;}

void TeacherDTO::printInfo(){
    cout << "ID: " << this->getId() << endl;
    cout << "Nome: " << this->getName() << endl;
    cout << "Idade: " << this->getAge() << endl;
    cout << "Salário: " << this->getSalary() << endl;
    cout << "Telefone: " << this->getPhone() << endl;
    cout << "--------------------------------------" << endl;
}

string TeacherDTO::getIdentifier(){
    return id;
}
#include "../../include/dto/StudentDTO.hpp"
#include <iostream>

StudentDTO::~StudentDTO(){}

void StudentDTO::setRa(string ra){this->ra=ra;}
void StudentDTO::setMajor(string major){this->major=major;}

string StudentDTO::getRa() const {return ra;}
string StudentDTO::getMajor()const {return major;}

void StudentDTO::printInfo(){
    cout << "RA: " << this->getRa() << endl;
    cout << "Nome: " << this->getName() << endl;
    cout << "Idade: " << this->getAge() << endl;
    cout << "Curso: " << this->getMajor() << endl;
    cout << "Telefone: " << this->getPhone() << endl;
    cout << "--------------------------------------" << endl;
}

string StudentDTO::getIdentifier(){
    return ra;
}
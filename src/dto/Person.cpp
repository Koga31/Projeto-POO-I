#include "../../include/dto/Person.hpp"


Person::~Person() {}

void Person::setName(string name) {this->name = name;}
void Person::setAge(int age){this->age = age;}
void Person::setPhone(string phone){this->phone = phone;}
string Person::getName(){return name;}
int Person::getAge(){return age;}
string Person::getPhone(){return phone;}
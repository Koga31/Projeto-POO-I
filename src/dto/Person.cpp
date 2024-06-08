#include "../../include/dto/Person.hpp"
#include <iostream>


Person::~Person() {}

void Person::setName(string name) {this->name = name;}
void Person::setAge(int age){this->age = age;}
void Person::setPhone(string phone){this->phone = phone;}
string Person::getName() const {return name;}
int Person::getAge() const {return age;}
string Person::getPhone() const {return phone;}

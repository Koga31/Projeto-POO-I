/*Classe simples usada como base para as classes de estudantes e
professores. Uma pessoa deve possuir nome, idade e telefone. */


#ifndef INCLUDE_PERSON_HPP
#define INCLUDE_PERSON_HPP

#include <string>
#include <memory>

using namespace std;

class Person {
	string name;
	int age;
	string phone;
public:
	Person(string _name="", int _age=0, string _phone ="" ):name(_name), age(_age), phone(_phone){}
	void setName(string name);
	void setAge(int age);
	void setPhone(string phone);
	string getName() const;
	int getAge() const;
	string getPhone() const;
	
	virtual string getIdentifier()=0;

	virtual void printInfo()=0;
	
	virtual ~Person();
};

#endif
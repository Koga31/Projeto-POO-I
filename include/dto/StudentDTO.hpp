/*Classe simples usada para transferir dados de estudantes entre diferentes
camadas do sistema. Herda da classe Person. Um estudante deve possuir
um curso e um RA para identificação. */


#ifndef STUDENTDTO_HPP
#define STUDENTDTO_HPP
#include "Person.hpp"
#include <memory>

class StudentDTO : public Person {
    private:
        string ra;
        string major;
    public:
        
        StudentDTO(string _name="", int _age=0, string _phone ="", string _ra="", string _major=""):Person(_name, _age, _phone), ra(_ra), major(_major){}
        virtual ~StudentDTO();
        void setRa(string ra);
        void setMajor(string major);
        string getRa() const;
        string getMajor() const;
        void printInfo();
        string getIdentifier();
};

#endif
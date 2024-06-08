#include "../../include/dao/StudentDAO.hpp"
#include "../../include/controller/College.hpp"
#include "../../include/utils/Utils.hpp"
#include "../../include/controller/Controller.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <memory>
using namespace std;

void StudentDAO::add(const shared_ptr<StudentDTO>& student){
    College::getStudents().insert({student->getRa(), student});
}

void StudentDAO::read(const shared_ptr<StudentDTO> &student){
    College::getStudents().at(student->getRa())->printInfo();
}

void StudentDAO::update(const shared_ptr<StudentDTO> &student, const int sel){
    
            string name;
            int age;
            string ra;
            string major;
            string phone;
            
            if(sel == 1)
            {  
                cout << "Digite o novo nome: " << endl;
                cin >> name;
                College::getStudents().at(student->getRa())->setName(name);
                cout << "Nome alterado com sucesso!" << endl;
            }
            else if(sel == 2)
            {
                cout << "Digite a nova idade: " << endl;
                cin >> age;
                College::getStudents().at(student->getRa())->setAge(age);
                cout << "Idade alterada com sucesso!" << endl;
            }
            else if(sel == 3)
            {
                cout << "Digite o novo curso: " << endl;
                cin >> major;
                student->setName(College::getStudents().at(student->getRa())->getName());
                student->setPhone(College::getStudents().at(student->getRa())->getPhone());
                student->setAge(College::getStudents().at(student->getRa())->getAge());
                student->setMajor(major);
                College::getStudents().at(student->getRa()) = student;
                cout << "Curso alterado com sucesso!" << endl;
            }
            else if(sel == 4)
            {
                cout << "Digite o novo telefone: " << endl;
                cin >> phone;
                College::getStudents().at(student->getRa())->setPhone(phone);
                cout << "Telefone alterado com sucesso!" << endl;
            }
            else
            {
                cout << "Opcao Invalida!" << endl;
            }
}

void StudentDAO::del(const shared_ptr<StudentDTO> &student){
    College::getStudents().erase(student->getRa());
}
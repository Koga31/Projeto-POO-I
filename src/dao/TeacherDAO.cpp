#include "../../include/dao/TeacherDAO.hpp"
#include "../../include/controller/College.hpp"
#include "../../include/utils/Utils.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <memory>

void TeacherDAO::add(const shared_ptr<TeacherDTO>& teacher)
{
    College::getTeachers().insert({teacher->getId(), teacher});
}

void TeacherDAO::read(const shared_ptr<TeacherDTO>& teacher)
{
    College::getTeachers().at(teacher->getId())->printInfo();
}

void TeacherDAO::update(const shared_ptr<TeacherDTO>& teacher, const int sel)
{ 
            string name;
            int age;
            string id;
            float salary;
            string phone;
            
            if(sel == 1)
            {  
                cout << "Digite o novo nome: " << endl;
                cin >> name;
                College::getTeachers().at(teacher->getId())->setName(name);
                cout << "Nome alterado com sucesso!" << endl;
            }
            else if(sel == 2)
            {
                cout << "Digite a nova idade: " << endl;
                cin >> age;
                College::getTeachers().at(teacher->getId())->setAge(age);
                cout << "Idade alterada com sucesso!" << endl;
            }
            else if(sel == 3)
            {
                cout << "Digite o novo salario: " << endl;
                cin >> salary;
                teacher->setName(College::getTeachers().at(teacher->getId())->getName());
                teacher->setPhone(College::getTeachers().at(teacher->getId())->getPhone());
                teacher->setAge(College::getTeachers().at(teacher->getId())->getAge());
                teacher->setSalary(salary);
                College::getTeachers().at(teacher->getId())= teacher;
                cout << "Curso alterado com sucesso!" << endl;
            }
            else if(sel == 4)
            {
                cout << "Digite o novo telefone: " << endl;
                cin >> phone;
                College::getTeachers().at(teacher->getId())->setPhone(phone);
                cout << "Telefone alterado com sucesso!" << endl;
            }
            else
            {
                cout << "Opcao Invalida!" << endl;
            }
}

void TeacherDAO::del(const shared_ptr<TeacherDTO> &teacher)
{
    College::getTeachers().erase(teacher->getId());
}
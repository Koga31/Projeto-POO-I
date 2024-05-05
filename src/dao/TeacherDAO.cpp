#include "../../include/dao/TeacherDAO.hpp"
#include "../../include/controller/College.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <memory>

void TeacherDAO::add(const shared_ptr<TeacherDTO>& teacher){
    College::getTeachers().insert({teacher->getId(), teacher});
}

void TeacherDAO::read(shared_ptr<TeacherDTO>& teacher){
    string name;
    int age;
    string phone;
    string id;
    float salary;

    cout << "Insira: nome | idade | telefone | id | salario |" << endl; 
    cin >> name >> age >> phone >> id >> salary;

    teacher = make_shared<TeacherDTO>(name, age, phone, id, salary);  
}

void TeacherDAO::update(TeacherDTO teacher){}
void TeacherDAO::del(const TeacherDTO teacher){}
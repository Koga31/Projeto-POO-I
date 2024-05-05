#include "../../include/dao/StudentDAO.hpp"
#include "../../include/controller/College.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <memory>

void StudentDAO::add(const shared_ptr<StudentDTO>& student){
    College::getStudents().insert({student->getRa(), student});
}

void StudentDAO::read(shared_ptr<StudentDTO>& student){
    string name;
    int age;
    string phone;
    string ra;
    string major;

    cout << "Insira: nome | idade | telefone | ra | curso |" << endl; 
    cin >> name >> age >> phone >> ra >> major;

    student = make_shared<StudentDTO>(name, age, phone, ra, major);
}

void StudentDAO::update(StudentDTO object){}
void StudentDAO::del(const StudentDTO object){}
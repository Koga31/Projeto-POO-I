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

void StudentDAO::update(const shared_ptr<StudentDTO> &student){
    College::getStudents().at(student->getRa()) = student;
}

void StudentDAO::del(const shared_ptr<StudentDTO> &student){
    College::getStudents().erase(student->getRa());
}
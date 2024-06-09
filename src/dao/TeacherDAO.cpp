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

void TeacherDAO::update(const shared_ptr<TeacherDTO>& teacher)
{ 
    College::getTeachers().at(teacher->getId()) = teacher;
}

void TeacherDAO::del(const shared_ptr<TeacherDTO> &teacher)
{
    College::getTeachers().erase(teacher->getId());
}
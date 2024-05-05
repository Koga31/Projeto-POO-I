#ifndef CLASSDAO_HPP
#define CLASSDAO_HPP
#include "../dao/AbstractDAO.hpp"
#include "../dto/ClassDTO.hpp"
#include "../controller/College.hpp"
using namespace std;

class ClassDAO : public AbstractDAO<ClassDTO>{

    public:
    ClassDAO(){}
    virtual ~ClassDAO(){}

    void add(const shared_ptr<ClassDTO>& classes)override;
    void read(shared_ptr<ClassDTO>& classes)override;
    void update(ClassDTO subject)override;
    void del(const ClassDTO subject)override;

    void addTeacher();
    void addStudent();

};

#endif
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

    void add(const shared_ptr<ClassDTO>& classObj)override;
    void read(const shared_ptr<ClassDTO>& classObj)override;
    void update(const shared_ptr<ClassDTO>& classObj)override;
    void del(const shared_ptr<ClassDTO> &classObj)override;

    vector<shared_ptr<ClassDTO>>::iterator findClassIterator(const shared_ptr<ClassDTO> &classObj);

    void addTeacher();
    void addStudent();

};

#endif
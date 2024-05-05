#ifndef TEACHERDAO_HPP
#define CLASSDAO_HPP
#include "../dao/AbstractDAO.hpp"
#include "../dto/TeacherDTO.hpp"

class TeacherDAO : public AbstractDAO<TeacherDTO> 
{

    public:
    TeacherDAO(){}
    virtual ~TeacherDAO(){}

    void add(const shared_ptr<TeacherDTO>& teacher) override;
    void read(shared_ptr<TeacherDTO>& teacher) override;
    void update(TeacherDTO teacher) override;
    void del(const TeacherDTO teacher) override;


};

#endif
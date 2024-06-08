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
    void read(const shared_ptr<TeacherDTO>& teacher) override;
    void update(const shared_ptr<TeacherDTO>& teacher, const int sel) override;
    void del(const shared_ptr<TeacherDTO>& teacher) override;
};

#endif
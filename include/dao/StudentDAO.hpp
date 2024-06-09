#ifndef STUDENTDAO_HPP
#define STUDENTDAO_HPP
#include "../dao/AbstractDAO.hpp"
#include "../dto/StudentDTO.hpp"
#include "../controller/College.hpp"
using namespace std;

class StudentDAO : public AbstractDAO<StudentDTO> {
    public:
    StudentDAO(){}
    virtual ~StudentDAO(){}

    //void add(argumentos) override: Adiciona um novo estudante a estrutura de dados students em College.

    void add(const shared_ptr<StudentDTO>& student) override;
    void read(const shared_ptr<StudentDTO> &student) override;
    void update(const shared_ptr<StudentDTO> &student) override;
    void del(const shared_ptr<StudentDTO> &student) override;

};

#endif
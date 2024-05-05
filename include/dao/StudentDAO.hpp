/*Classe responsável pelo acesso aos dados dos estudantes, como operações
de criar, ler, atualizar e deletar. Herda da classe AbstractDAO com o tipo
StudentDTO. */

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
    void read(shared_ptr<StudentDTO>& student) override;
    void update(StudentDTO object) override;
    void del(const StudentDTO object) override;

};

#endif
/*Classe template abstrata responsável por definir a estrutura comum para as
classes DAO das respectivas entidades do sistema. Ela fornece a base para
as operações CRUD (Create, Read, Update, Delete) que serão
implementadas pelas classes derivadas específicas para cada entidade.
Será necessário definir um template <T> que será usado para representar o
tipo de entidade que o DAO específico irá gerenciar. */


#ifndef ABSTRACTDAO_HPP
#define ABSTRACTDAO_HPP
using namespace std;
#include <iostream>
#include <memory>

template <typename T>

class AbstractDAO {

    public:

    AbstractDAO(){}
    virtual ~AbstractDAO(){}
    
    virtual void add(const shared_ptr<T>& object)=0;
    virtual void read(const shared_ptr<T>& object)=0;
    virtual void update(const shared_ptr<T>& object)=0;
    virtual void del(const shared_ptr<T>& object)=0;

};

#endif
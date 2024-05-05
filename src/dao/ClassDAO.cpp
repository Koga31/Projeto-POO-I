#include "../../include/dao/ClassDAO.hpp"
#include "../../include/controller/College.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <memory>

void ClassDAO::add(const shared_ptr<ClassDTO>& classes)
{
    College::getSubjects().push_back(classes);
}

void ClassDAO::read(shared_ptr<ClassDTO>& classes)
{

    string code;
    string name;
    string description;
    int year;
    int semesterNumber;

    cout << "Insira: codigo | nome | descricao | ano | numSemestre |" << endl; 
    cin >> code >> name >> description >> year >> semesterNumber;


    classes = make_shared<ClassDTO>(code, name, description, year, semesterNumber);

}

void ClassDAO::addTeacher()
{

    string teacher;
    int i;
    cout << "Digite Qual Disciplina voce deseja adicionar um professor [1,2,3..]" << endl;
    cin >> i;

    if (i >= 1 && i <= College::getSubjects().size()) {
    shared_ptr<ClassDTO> choice = College::getSubjects()[i - 1];
        cout << "Codigo: " << choice->getCode() << endl;
        cout << "Nome: " << choice->getName() << endl;
        cout << endl;

        cout << "Insira o nome do professor: " << endl;
        cin >> teacher;
        choice->setTeacher(teacher);

        
    } 
    else 
    {
    cout << "Numero de disciplina invalido." << endl;
    }


}

void ClassDAO::addStudent()
{

    string student;
    int i;
    cout << "Digite Qual Disciplina voce deseja adicionar um aluno [1,2,3..]" << endl;
    cin >> i;

    if (i >= 1 && i <= College::getSubjects().size()) {
    shared_ptr<ClassDTO> choice = College::getSubjects()[i - 1];
        cout << "Codigo: " << choice->getCode() << endl;
        cout << "Nome: " << choice->getName() << endl;
        cout << "Professor:" << choice->getTeacher();
        cout << endl;

        cout << "Insira o nome do aluno: " << endl;
        cin >> student;
        choice->getClassroomStudents().push_back(student);
    } 
    else 
    {
    cout << "Numero de disciplina invalido." << endl;
    }

}


void ClassDAO::update(ClassDTO subject){}
void ClassDAO::del(const ClassDTO subject){}
#include "../../include/dao/ClassDAO.hpp"
#include "../../include/controller/College.hpp"
#include "../../include/utils/Utils.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

void ClassDAO::add(const shared_ptr<ClassDTO>& classObj)
{
    College::getSubjects().push_back(classObj);
}

void ClassDAO::read(const shared_ptr<ClassDTO>& classObj){
    cout << "Codigo: " << classObj->getCode() << endl;
    cout << "Nome: " << classObj->getName() << endl;
    cout << "Ano: " << classObj->getYear() << endl;
    cout << "Semestre: " << classObj->getSemesterNumber() << endl;
	cout << "Professor: " << classObj->getTeacher() << endl;
}

void ClassDAO::addTeacher()
{

    string teacher;
    int i;
    cout << "Digite Qual Disciplina voce deseja adicionar um professor [1,2,3..]" << endl;
    cin >> i;

    if(i >= 1 && i <= College::getSubjects().size()){
        shared_ptr<ClassDTO> choice = College::getSubjects()[i - 1];
        cout << "Codigo: " << choice->getCode() << endl;
        cout << "Nome: " << choice->getName() << endl;
        cout << endl;

        cout << "Insira o nome do professor: " << endl;
        cin >> teacher;
        choice->setTeacher(teacher);
   
    }else{
        cout << "Numero de disciplina invalido." << endl;
    }


}

void ClassDAO::addStudent()
{
    int i;
    cout << "Digite Qual Disciplina voce deseja adicionar um aluno [1,2,3..]" << endl;
    cin >> i;

    if(i >= 1 && i <= College::getSubjects().size()){
        shared_ptr<ClassDTO> choice = College::getSubjects()[i - 1];
        cout << "Codigo: " << choice->getCode() << endl;
        cout << "Nome: " << choice->getName() << endl;
        cout << "Professor:" << choice->getTeacher() << endl;

        string raSearch;
        string exitStr = 0;
        cin >> raSearch;

        while(College::doesNotHaveStudent(raSearch)){
            cout << "RA inválido, tente novamente.\n" << endl;
            cout << "Insira o RA do aluno: " << endl;
            cin >> raSearch;
            if(raSearch == exitStr){
                return;
            }
        }

        choice->getClassGradesStudents().insert({raSearch, 0});
    }else{
        cout << "Numero de disciplina invalido." << endl;
    }

}


void ClassDAO::update(const shared_ptr<ClassDTO>& classObj){
    shared_ptr<ClassDAO> ClassDAO;
    College::getSubjects().erase(findClassIterator(classObj));
    College::getSubjects().push_back(classObj);
}

void ClassDAO::del(const shared_ptr<ClassDTO> &classObj){
    College::getSubjects().erase(findClassIterator(classObj));
}

vector<shared_ptr<ClassDTO>>::iterator ClassDAO::findClassIterator(const shared_ptr<ClassDTO> &classObj){
    string code = classObj->getCode();
    int year = classObj->getYear();
    int semester = classObj->getSemesterNumber();

    vector<shared_ptr<ClassDTO>>::iterator i = find_if(College::getSubjects().begin(), College::getSubjects().end(), [&code, &year, &semester](shared_ptr<ClassDTO> classIt){
		    return((classIt->getCode() == code) && (classIt->getYear() == year) && (classIt->getSemesterNumber() == semester));
		}
	);
    return i;
}
#include <exception>
#include <iostream>

#include "../../include/controller/Controller.hpp"
#include "../../include/menu/Menu.hpp"
#include "../../include/utils/Utils.hpp"
#include "../../include/system/SysInfo.hpp"
#include "../../include/dao/ClassDAO.hpp"
#include "../../include/dao/StudentDAO.hpp"
#include "../../include/dao/TeacherDAO.hpp"

Controller::Controller() {}

Controller::~Controller() {}


//Start------------------------------------------------------------------------


void Controller::start() {
	vector<string> menuItens { "Estudantes", "Professores", "Disciplinas", "Relatorios",
			"Ajuda", "Sobre", "Sai do programa" };
	vector<void (Controller::*)()> functions { &Controller::actionStudents,
			&Controller::actionTeachers, &Controller::actionSubjects, &Controller::actionReports,&Controller::actionHelp, &Controller::actionAbout };
	launchActions("Menu Principal", menuItens, functions);
}


//Menu Estudantes ------------------------------------------------------------------------


void Controller::actionStudents() {
	vector<string> menuStudents { "Inserir estudante",
			"Visualizar todos os estudantes", "Pesquisar estudante por RA",
			"Alterar estudante", "Voltar ao menu principal" };
	vector<void (Controller::*)()> functions { &Controller::actionInsertStudent,
			&Controller::actionViewStudents, &Controller::actionSearchRA,
			&Controller::actionChangeStudent, &Controller::actionReturnMenu };
	launchActions("Menu Estudantes", menuStudents, functions);
}


//Menu Professores ------------------------------------------------------------------------


void Controller::actionTeachers() {
	vector<string> menuTeachers { "Inserir professor",
			"Visualizar todos os professores", "Pesquisar professor por ID",
			"Alterar professor", "Voltar ao menu principal" };
	vector<void (Controller::*)()> functions { &Controller::actionInsertTeacher,
			&Controller::actionViewTeacher, &Controller::actionSearchID,
			&Controller::actionChangeTeacher, &Controller::actionReturnMenu };
	launchActions("Menu Professores", menuTeachers, functions);
}


//Menu Materias------------------------------------------------------------------------


void Controller::actionSubjects()
{
	vector<string> menuSubjects { "Inserir Turma",
			"Inserir Professor", "Inserir Aluno",
			"Visualizar todas as disciplinas", "Voltar ao menu principal" };
	vector<void (Controller::*)()> functions { &Controller::actionInsertSubject,
			&Controller::actionInsertClassTeacher, &Controller::actionInsertClassStudent,
			&Controller::actionViewSubject, &Controller::actionReturnMenu };
	launchActions("Menu Disciplinas", menuSubjects, functions);
}


//Relatorio ------------------------------------------------------------------------


void Controller::actionReports()
{
	return;
}


//Help ------------------------------------------------------------------------


void Controller::actionHelp(void) {
	Utils::printMessage(SysInfo::getVersion() + " | Help");
	
}

//Sobre ------------------------------------------------------------------------


void Controller::actionAbout(void) {
	Utils::printMessage(SysInfo::getVersion() + " | About");
	
}


//Controle de Escolhas ---------------------------------------------------------


void Controller::launchActions(string title, vector<string> menuItens,
		vector<void (Controller::*)()> functions) {
	try {
		Menu menu(menuItens, title, "Sua opcao: ");
		menu.setSymbol("*");

		while (int choice = menu.getChoice()) {
			(this->*functions.at(choice - 1))();
		}
	} catch (const exception &myException) {
		Utils::printMessage(
				"Unexpected problem launching actions. "
						+ string(myException.what()));
	}
}


//Student ------------------------------------------------------------------------


void Controller::actionInsertStudent() {
	StudentDAO studentDAO;
	shared_ptr<StudentDTO> studentDTO = make_shared<StudentDTO>();
	studentDAO.read(studentDTO);
	studentDAO.add(studentDTO);
}

void Controller::actionViewStudents(void) {
	
    for (const auto& pair : College::getStudents()) {
        cout << "RA: " << pair.first << endl; 
        shared_ptr<Person> student = pair.second;

        // Verifica se o ponteiro não é nulo antes de acessar os membros
        if (student) {
            cout << "Nome: " << student->getName() << endl;
            cout << "Idade: " << student->getAge() << endl;
        } else {
            cout << "Erro: Ponteiro para aluno nulo." <<endl;
        }
    }

}

void Controller::actionSearchRA(void) {
	Utils::printMessage("Place holder function. Code was not written yet!\n");
}

void Controller::actionChangeStudent(void) {
	Utils::printMessage("Place holder function. Code was not written yet!\n");
}


//Teacher ------------------------------------------------------------------------


void Controller::actionInsertTeacher() {
	TeacherDAO teacherDAO;
	shared_ptr<TeacherDTO> teacherDTO = make_shared<TeacherDTO>();
	teacherDAO.read(teacherDTO);
	teacherDAO.add(teacherDTO);
}

void Controller::actionViewTeacher(void) {
	for (const auto& pair : College::getTeachers()) {
		cout << "ID: " << pair.first << endl; 
		shared_ptr<Person> teacher = pair.second;

		// Verifica se o ponteiro não é nulo antes de acessar os membros
		if (teacher) {
			cout << "Nome: " << teacher->getName() << endl;
			cout << "Idade: " << teacher->getAge() << endl;
		} else {
			cout << "Erro: Ponteiro para professor nulo." <<endl;
		}
	}
}

void Controller::actionSearchID(void) {
	Utils::printMessage("Place holder function. Code was not written yet!\n");
}

void Controller::actionChangeTeacher(void) {
	Utils::printMessage("Place holder function. Code was not written yet!\n");
}


//Subject ------------------------------------------------------------------------


void Controller::actionInsertSubject() 
{
	
	ClassDAO classDAO;
	shared_ptr<ClassDTO> classDTO = make_shared<ClassDTO>();
	classDAO.read(classDTO);
	classDAO.add(classDTO);

}

void Controller::actionInsertClassTeacher(void) 
{

	ClassDAO classDAO;
	shared_ptr<ClassDTO> classDTO = make_shared<ClassDTO>();
	classDAO.addTeacher();

}

void Controller::actionInsertClassStudent(void) {
	ClassDAO classDAO;
	shared_ptr<ClassDTO> classDTO = make_shared<ClassDTO>();
	classDAO.addStudent();
}

void Controller::actionViewSubject(void) {

	for (const auto& classes: College::getSubjects()) {
       
        // Verifica se o ponteiro não é nulo antes de acessar os membros
        if (classes) {
            cout << "Codigo: " << classes->getCode() << endl;
            cout << "Nome: " << classes->getName() << endl;
            cout << "Ano: " << classes->getYear() << endl;
            cout << "Semestre: " << classes->getSemesterNumber() << endl;
        } else {
            cout << "Erro: Ponteiro para disciplina nulo." << endl;
        }
    }

}


//Menu ------------------------------------------------------------------------


void Controller::actionReturnMenu(void) {
	Utils::printMessage("Place holder function. Code was not written yet!\n");
}
void actionToDo()
{
	Utils::printMessage("Place holder function. Code was not written yet!\n");
}
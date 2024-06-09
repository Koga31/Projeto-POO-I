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
			"Alterar estudante", "Excluir estudante", "Voltar ao menu principal" };
	vector<void (Controller::*)()> functions { &Controller::actionInsertStudent,
			&Controller::actionViewStudents, &Controller::actionSearchRA,
			&Controller::actionChangeStudent, &Controller::actionDeleteStudent, &Controller::actionReturnMenu };
	launchActions("Menu Estudantes", menuStudents, functions);
}


//Menu Professores ------------------------------------------------------------------------


void Controller::actionTeachers() {
	vector<string> menuTeachers { "Inserir professor",
			"Visualizar todos os professores", "Pesquisar professor por ID",
			"Alterar professor", "Excluir professor", "Voltar ao menu principal" };
	vector<void (Controller::*)()> functions { &Controller::actionInsertTeacher,
			&Controller::actionViewTeacher, &Controller::actionSearchID,
			&Controller::actionChangeTeacher, &Controller::actionDeleteTeacher, &Controller::actionReturnMenu };
	launchActions("Menu Professores", menuTeachers, functions);
}


//Menu Materias------------------------------------------------------------------------


void Controller::actionSubjects()
{
	vector<string> menuSubjects { "Inserir Turma",
			"Inserir Professor", "Inserir Aluno",
			"Visualizar todas as disciplinas", "Alterar disciplina", "Excluir disciplina", "Voltar ao menu principal" };
	vector<void (Controller::*)()> functions { &Controller::actionInsertSubject,
			&Controller::actionInsertClassTeacher, &Controller::actionInsertClassStudent,
			&Controller::actionViewSubject, &Controller::actionChangeSubject, &Controller::actionDeleteSubject, &Controller::actionReturnMenu };
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
	string name;
    int age;
    string phone;
    string ra;
    string major;

    while(1){
        Utils::printMessage("Digite o nome: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> name;
        if(name == "0"){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyName(name)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite a idade: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> age;
        if(age == 0){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyAge(age)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite o telefone: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> phone;
        if(phone == "0"){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyPhone(phone)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite o RA: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> ra;
        if(ra == "0"){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyRa(ra)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite o curso: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> major;
        if(major == "0"){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyMajor(major)){
                break;
            }else{
                continue;
            }
        }
    }

	unique_ptr<StudentDAO> studentDAO = make_unique<StudentDAO>();
	studentDAO->add(make_shared<StudentDTO>(name, age, phone, ra, major));
}

void Controller::actionViewStudents(void) {
	unique_ptr<StudentDAO> studentDAO = make_unique<StudentDAO>();
	shared_ptr<StudentDTO> studentDTO;
	string ra;
    for (const auto& pair : College::getStudents()){

        // Verifica se o ponteiro não é nulo antes de acessar os membros
        if (pair.second){
		    cout << "--------------------------------------" << endl;
			ra = pair.second->getIdentifier();
			studentDTO = make_shared<StudentDTO>();
			studentDTO->setRa(ra);
			studentDAO->read(studentDTO);
        }else{
            cout << "Erro: Ponteiro para aluno nulo." <<endl;
        }
    }

}

void Controller::actionSearchRA(void) {
	cout << "Insira o RA do aluno a ser procurado:" << endl;
	string ra;
	cin >> ra;
	if(College::doesNotHaveStudent(ra)){
		cout << "Aluno inexistente." << endl;
	}else{
		cout << "--------------------------------------" << endl;
		College::getStudents().at(ra)->printInfo();
	}
}

void Controller::actionChangeStudent(void) {
    while(1)
    {
    int sel;
	cout << "Digite o RA do aluno que deseja alterar informacoes(0 para sair.):" << endl;
    string ra;
    cin >> ra;
    if(ra == "0")
    {
        Utils::printMessage("Operação cancelada.");
        return;
    }
    else if(College::doesNotHaveStudent(ra))
    {
        cout << "RA invalido" << endl;
    }
    else 
    {
        
    unique_ptr<StudentDAO> studentDAO = make_unique<StudentDAO>();
    cout << "Informacoes: " << endl;
    College::getStudents().at(ra)->printInfo();
    cout << "Forneca os dados alterados:" << endl;
        
    string name;
    int age;
    string phone;
    string major;

    while(1){
        Utils::printMessage("Digite o novo nome: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> name;
        if(name == "0"){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyName(name)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite a nova idade: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> age;
        if(age == 0){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyAge(age)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite o novo telefone: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> phone;
        if(phone == "0"){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyPhone(phone)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite o novo curso: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> major;
        if(major == "0"){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyMajor(major)){
                break;
            }else{
                continue;
            }
        }
    }

        shared_ptr<StudentDTO> studentDTO = make_shared<StudentDTO>();
        studentDTO->setRa(ra);
        studentDTO->setName(name);
        studentDTO->setAge(age);
        studentDTO->setPhone(phone);
        studentDTO->setMajor(major);
        studentDAO->update(studentDTO);      
    }
    }
}

void Controller::actionDeleteStudent(){
	string ra;
	while(1){
		Utils::printMessage("Insira o RA do aluno a ser excluído:");
		cout << "Digite 0 para cancelar a operação." << endl;
		cin >> ra;
		if(ra == "0"){
			cout << "Operação cancelada." << endl;
			return;
		}else{
			if(College::doesNotHaveStudent(ra)){
				cout << "Estudante inexistente!" << endl;
				continue;
			}else{
				shared_ptr<StudentDTO> studentDel = make_shared<StudentDTO>();
				studentDel->setRa(ra);
				unique_ptr<StudentDAO> studentDAO = make_unique<StudentDAO>();
				studentDAO->del(studentDel);
				cout << "Estudante excluído." << endl;
				break;
			}
		}
	}
}

//Teacher ------------------------------------------------------------------------


void Controller::actionInsertTeacher() {
	unique_ptr<TeacherDAO> teacherDAO = make_unique<TeacherDAO>();
	string name;
    int age;
    string phone;
    string id;
    float salary;

    while(1){
        Utils::printMessage("Digite o nome: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> name;
        if(name == "0"){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyName(name)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite a idade: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> age;
        if(age == 0){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyAge(age)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite o telefone: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> phone;
        if(phone == "0"){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyPhone(phone)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite o ID: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> id;
        if(id == "0"){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyId(id)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite o salário: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> salary;
        if(salary == 0){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifySalary(salary)){
                break;
            }else{
                continue;
            }
        }
    }

	teacherDAO->add(make_shared<TeacherDTO>(name, age, phone, id, salary));
}

void Controller::actionViewTeacher(void) {
	for (const auto& pair : College::getTeachers()) {
		unique_ptr<TeacherDAO> teacherDAO = make_unique<TeacherDAO>();
		shared_ptr<TeacherDTO> teacherDTO;
		string id;
		// Verifica se o ponteiro não é nulo antes de acessar os membros
		if (pair.second) {
			cout << "--------------------------------------" << endl;
			id = pair.second->getIdentifier();
			teacherDTO = make_shared<TeacherDTO>();
			teacherDTO->setId(id);
			teacherDAO->read(teacherDTO);
		} else {
			cout << "Erro: Ponteiro para professor nulo." <<endl;
		}
	}
}

void Controller::actionSearchID(void) {
	cout << "Insira o ID do professor a ser procurado:" << endl;
	string id;
	cin >> id;
	if(College::doesNotHaveTeacher(id)){
		cout << "Professor inexistente." << endl;
	}else{
		cout << "--------------------------------------" << endl;
		College::getTeachers().at(id)->printInfo();
	}
}

void Controller::actionChangeTeacher(void) {
	while(1)
    {
    int sel;
	cout << "Digite o ID do professor que deseja alterar informacoes(0 para sair.):" << endl;
    string id;
    cin >> id;
    if(id == "0")
    {
        Utils::printMessage("Operação cancelada.");
        return;
    }
    else if(College::doesNotHaveTeacher(id))
    {
        cout << "ID invalido" << endl;
    }
    else 
    {
        
        unique_ptr<TeacherDAO> teacherDAO = make_unique<TeacherDAO>();
        cout << "Informacoes: " << endl;
        College::getTeachers().at(id)->printInfo();
        cout << "Digite os novos dados:" << endl;
        	string name;
    int age;
    string phone;
    float salary;

    while(1){
        Utils::printMessage("Digite o nome: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> name;
        if(name == "0"){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyName(name)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite a idade: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> age;
        if(age == 0){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyAge(age)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite o telefone: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> phone;
        if(phone == "0"){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifyPhone(phone)){
                break;
            }else{
                continue;
            }
        }
    }

    while(1){
        Utils::printMessage("Digite o salário: ");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> salary;
        if(salary == 0){
            Utils::printMessage("Operação cancelada.");
            return;
        }else{
            if(verifySalary(salary)){
                break;
            }else{
                continue;
            }
        }
    }
        shared_ptr<TeacherDTO> teacherDTO = make_shared<TeacherDTO>();
        teacherDTO->setId(id);
        teacherDTO->setAge(age);
        teacherDTO->setName(name);
        teacherDTO->setPhone(phone);
        teacherDTO->setSalary(salary);
        teacherDAO->update(teacherDTO);      
    }
    }
}

void Controller::actionDeleteTeacher(){
	string id;
	while(1){
		Utils::printMessage("Insira o ID do professor a ser excluído:");
		cout << "Digite 0 para cancelar a operação." << endl;
		cin >> id;
		if(id == "0"){
			cout << "Operação cancelada." << endl;
			return;
		}else{
			if(College::doesNotHaveTeacher(id)){
				cout << "Professor inexistente!" << endl;
				continue;
			}else{
				shared_ptr<TeacherDTO> teacherDel = make_shared<TeacherDTO>();
				teacherDel->setId(id);
				unique_ptr<TeacherDAO> teacherDAO = make_unique<TeacherDAO>();
				teacherDAO->del(teacherDel);
				cout << "Professor excluído." << endl;
				break;
			}
		}
	}
}

//Subject ------------------------------------------------------------------------


void Controller::actionInsertSubject() 
{
	string code;
    string name;
    string description;
    int year;
    int semesterNumber;

    while(1){
        Utils::printMessage("Digite o código:");
        cout << "Digite 0 para sair." << endl;
        cin >> code;
        if(code == "0"){
            cout << "Operação cancelada." << endl;
            return;
        }

        Utils::printMessage("Digite o ano:");
        cout << "Digite 0 para sair." << endl;
        cin >> year;
        if(year == 0){
            cout << "Operação cancelada." << endl;
            return;
        }

        Utils::printMessage("Digite o semestre:");
        cout << "Digite 0 para sair." << endl;
        cin >> semesterNumber;
        if(semesterNumber == 0){
            cout << "Operação cancelada." << endl;
            return;
        }
        
        if(College::doesNotHaveClass(code, year, semesterNumber)){
            break;
        }else{
            cout << "Classe já existente." << endl;
        }
    }

    while(1){
        Utils::printMessage("Digite o nome da Disciplina:");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> name;
        if(name == "0"){
            cout << "Operação cancelada." << endl;
            return;
        }
        if(verifyName(name)){
            break;
        }else{
            continue;
        }
    }


    Utils::printMessage("Digite a ementa:");
    cout << "Digite 0 para cancelar a operação." << endl;
    cin >> description;
    if(description == "0"){
        cout << "Operação cancelada." << endl;
        return;
    }

	unique_ptr<ClassDAO> classDAO = make_unique<ClassDAO>();
	classDAO->add(make_shared<ClassDTO>(code, name, description, year, semesterNumber));

}

void Controller::actionInsertClassTeacher(void) 
{

	ClassDAO classDAO;
	classDAO.addTeacher();

}

void Controller::actionInsertClassStudent(void) {
	ClassDAO classDAO;
	classDAO.addStudent();
}

void Controller::actionViewSubject(void) {
    unique_ptr<ClassDAO> classDAO = make_unique<ClassDAO>();
	for (const auto& classObj: College::getSubjects()) {
       
        // Verifica se o ponteiro não é nulo antes de acessar os membros
        if (classObj) {
            classDAO->read(classObj);
        } else {
            cout << "Erro: Ponteiro para disciplina nulo." << endl;
        }
    }

}

void Controller::actionDeleteSubject(){
	string code;
	int year;
	int semester;
	while(1){
		Utils::printMessage("Insira o código da Turma a ser excluída:");
		cout << "Digite 0 para cancelar a operação." << endl;
		cin >> code;
		Utils::printMessage("Insira o ano da Turma a ser excluída:");
		cout << "Digite 0 para cancelar a operação." << endl;
		cin >> year;
		Utils::printMessage("Insira o semestre da Turma a ser excluída:");
		cout << "Digite 0 para cancelar a operação." << endl;
		cin >> semester;
		if(code == "0"){
			cout << "Operação cancelada." << endl;
			return;
		}else{
			if(College::doesNotHaveClass(code, year, semester)){
				cout << "Turma inexistente!" << endl;
				continue;
			}else{
				shared_ptr<ClassDTO> classDel = make_shared<ClassDTO>();
				classDel->setCode(code);
				classDel->setYear(year);
				classDel->setSemesterNumber(semester);
				unique_ptr<ClassDAO> classDAO = make_unique<ClassDAO>();
				classDAO->del(classDel);
				cout << "Turma excluída." << endl;
				break;
			}
		}
	}
}

void Controller::actionChangeSubject()
{
    string code;
	int year;
	int semester;
    while(1){
		Utils::printMessage("Insira o código da Turma a ser modificada:");
		cout << "Digite 0 para cancelar a operação." << endl;
		cin >> code;
		Utils::printMessage("Insira o ano da Turma a ser modificada:");
		cout << "Digite 0 para cancelar a operação." << endl;
		cin >> year;
		Utils::printMessage("Insira o semestre da Turma a ser modificada:");
		cout << "Digite 0 para cancelar a operação." << endl;
		cin >> semester;
		if(code == "0"){
			cout << "Operação cancelada." << endl;
			return;
		}
        else
        {
			if(College::doesNotHaveClass(code, year, semester)){
				cout << "Turma inexistente!" << endl;
				continue;
			}
            else
            {
                string name;
                string description;
                string teacher;       

    while(1){
        Utils::printMessage("Digite o novo nome da Disciplina:");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> name;
        if(name == "0"){
            cout << "Operação cancelada." << endl;
            return;
        }
        if(verifyName(name)){
            break;
        }else{
            continue;
        }
        }
    Utils::printMessage("Digite a nova ementa:");
    cout << "Digite 0 para cancelar a operação." << endl;
    cin >> description;
    if(description == "0"){
        cout << "Operação cancelada." << endl;
        return;
    }
    while(1){
        Utils::printMessage("Digite o nome do novo professor da Disciplina:");
        cout << "Digite 0 para cancelar a operação." << endl;
        cin >> teacher;
        if(teacher == "0"){
            cout << "Operação cancelada." << endl;
            return;
        }
        if(verifyName(teacher)){
            break;
        }else{
            continue;
        }
        }
    
				shared_ptr<ClassDTO> classDTO = make_shared<ClassDTO>();
				classDTO->setCode(code);
				classDTO->setYear(year);
				classDTO->setSemesterNumber(semester);
                classDTO->setName(name);
                classDTO->setDescription(description);
                classDTO->setTeacher(teacher);
				shared_ptr<ClassDAO> classDAO = make_shared<ClassDAO>();
				classDAO->update(classDTO);
				cout << "Turma modificada." << endl;
				break;
			}
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

//Verificadores ---------------------------------------------------------------

bool Controller::verifyString(const string& str){

    for(char c: str){
        if((c > 90 || c < 65) && (c < 97 || c > 122)){
            return false;
        }
    }
    return true;

}

bool Controller::verifyName(const string& name){
    if((name.size() < 2) || (!verifyString(name))){
        cout << "Nome inválido!" << endl;
        return false;
    }else{
        return true;
    }
}

bool Controller::verifyMajor(const string& major){
    if(!verifyString(major)){
        cout << "Curso inválido!" << endl;
        return false;
    }else{
        return true;
    }
}

bool Controller::verifyAge(const int& age){
    if(age > 0){
        return true;
    }else{
        cout << "Idade inválida!" << endl;
        return false;
    }
}

bool Controller::verifyPhone(const string& phone){

    if(phone.size() == 11){
        for(char c: phone){
            if(c > 57 || c < 48){
                return false;
            }
        }
        return true;
    }else{
        cout << "Telefone inválido!" << endl;
        return false;
    }

}

bool Controller::verifyRa(const string& ra)
{
    if(ra.size() == 6){
        for(char c: ra){
            if(c > 57 || c < 48){
                cout << "ID inválido!" << endl;
                return false;
            }
        }
        if(College::doesNotHaveStudent(ra)){
            return true;
        }else{
            cout << "RA já existente!" << endl;
            return false;
        }
    }else{
        cout << "RA inválido!" << endl;
        return false;
    }

}

bool Controller::verifySalary(const float& salary){
    if(salary < 1640){
        cout << "Salário inválido!" << endl;
        return false;
    }else{
        return true;
    }
}

bool Controller::verifyId(const string& id)
{
    if(id.size() == 6){
        for(char c: id){
            if(c > 57 || c < 48){
                cout << "ID inválido!" << endl;
                return false;
            }
        }
        if(College::doesNotHaveTeacher(id)){
            return true;
        }else{
            cout << "ID já existente!" << endl;
            return false;
        }
    }else{
        cout << "ID inválido!" << endl;
        return false;
    }

}
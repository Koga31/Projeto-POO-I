#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <string>
#include <vector>
#include <memory>

using namespace std;

#include "College.hpp"

class Controller final
{
private:
	void actionStudents();
	void actionTeachers();
	void actionSubjects();
	void actionReports();
	void actionHelp(void);
	void actionAbout(void);
	void launchActions(string title, vector<string> menuItens, vector<void (Controller::*)()> functions);


	void actionInsertStudent();
	void actionViewStudents(void);
	void actionSearchRA(void);
	void actionChangeStudent(void);


	void actionInsertTeacher();
	void actionViewTeacher(void);
	void actionSearchID(void);
	void actionChangeTeacher(void);


	void actionInsertSubject();
	void actionInsertClassTeacher();
	void actionInsertClassStudent();
	void actionViewSubject(void);
	

	void actionReturnMenu(void);
	void actionToDo(void);
	
public:
	Controller();
	virtual ~Controller();
	void start();

};


#endif
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
	void actionDeleteStudent();


	void actionInsertTeacher();
	void actionViewTeacher(void);
	void actionSearchID(void);
	void actionChangeTeacher(void);
	void actionDeleteTeacher();


	void actionInsertSubject();
	void actionInsertClassTeacher();
	void actionInsertClassStudent();
	void actionViewSubject(void);
	void actionChangeSubject();
	void actionDeleteSubject();
	

	void actionReturnMenu(void);
	void actionToDo(void);

    bool verifyString(const string& str);
    bool verifyName(const string& name);
    bool verifyMajor(const string& major);
    bool verifyAge(const int& age);
    bool verifyPhone(const string& phone);
    bool verifyRa(const string& ra);
	bool verifyId(const string& id);
	bool verifySalary(const float& salary);
	
public:
	Controller();
	virtual ~Controller();
	void start();

};


#endif
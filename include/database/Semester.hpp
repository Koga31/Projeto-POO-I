/*Representa um semestre específico, incluindo o ano e o número do
semestre. */


#ifndef SEMESTER_HPP
#define SEMESTER_HPP
#include <iostream>
using namespace std;

class Semester
{

private:
    int year;
    int semesterNumber;

public:
    Semester(int year, int semesterNumber):year(year), semesterNumber(semesterNumber){}
    virtual ~Semester();
    void setYear(int year);
    void setSemesterNumber(int semesterNumber);
    int getYear();
    int getSemesterNumber();
};

#endif

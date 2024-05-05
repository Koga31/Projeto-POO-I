#include "../../include/database/Semester.hpp"
using namespace std;

Semester::~Semester(){}

void Semester::setSemesterNumber(int semesterNumber){ this->semesterNumber = semesterNumber; }
void Semester::setYear(int year){ this->year = year; }

int Semester::getYear(){ return year; }
int Semester::getSemesterNumber(){ return semesterNumber; }

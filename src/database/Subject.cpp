#include "../../include/database/Subject.hpp"
using namespace std;

Subject::~Subject(){}

void Subject::setCode(string code){ this->code = code; }
void Subject::setName(string name){ this->name = name; }
void Subject::setDescription(string description){ this->description = description; }

string Subject::getCode(){ return code; }
string Subject::getName(){ return name; }
string Subject::getDescription(){ return description; }

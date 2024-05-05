#include "../../include/dto/StudentDTO.hpp"

StudentDTO::~StudentDTO(){}

void StudentDTO::setRa(string ra){this->ra=ra;}
void StudentDTO::setMajor(string major){this->major=major;}

string StudentDTO::getRa(){return ra;}
string StudentDTO::getMajor(){return major;}

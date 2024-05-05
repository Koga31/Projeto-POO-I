#include "../../include/utils/Utils.hpp"
#include "../../include/system/SysInfo.hpp"

#include <iostream>

void Utils::printMessage(string text)
{
	cout << "* " << SysInfo::getSystemName() << " message: " << text << endl;
}

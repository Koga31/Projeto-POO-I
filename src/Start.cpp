#include <exception>
#include <memory>
#include <string>

#include "../include/controller/Controller.hpp"
#include "../include/system/SysInfo.hpp"
#include "../include/utils/Utils.hpp"

using namespace std;

void welcome(void);
void bye(void);

int main(int argc, char *argv[]) {
	welcome();
	try {
		(make_unique<Controller>())->start(); //Controler*
	} catch (const exception &myException) {
		Utils::printMessage("Unexpected problem. Program aborted. "+ string(myException.what()));
		exit(1);
	}

	bye();
	return 0;
}

void welcome() {
	Utils::printMessage(SysInfo::getFullVersion());
	Utils::printMessage("Running now...");
}

void bye() {
	Utils::printMessage("Finished");
}
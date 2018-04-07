#include <iostream>

#include "signalhandler.h"

int main()
{
	SignalHandler::setupSignalHandlers();

	try {
		int* p = nullptr;
		*p = NULL;
		/*int a = 0;
		int b = 10 / a;*/
	}
	catch (SignalException& e) {
		std::cout << e.what();
	}
}
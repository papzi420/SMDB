#include "stdafx.h"
#include "misc.h"

namespace SMDB {
	//TODO: Make this cross-platform
	void Misc::error(std::string str) {
#ifdef _WIN32
		SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE), 0x0C);
		printf("%s\nFatal error...\nPress any key to quit...\n", str.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE), 0x0F);
#else
		printf("%s\e[91m\nFatal error...\nPress any key to quit...\n\e[39m", str.c_str());
#endif
		_getch();
		printf("Quiting...");
		exit(1);
	}
}
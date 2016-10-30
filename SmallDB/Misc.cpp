#include "stdafx.h"
#include "misc.h"

namespace SMDB {
	void Misc::error(std::string str) {
		SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE), 0x0C);
		printf("%s\nFatal error...\nPress any key to quit...\n", str.c_str());
		_getch();
		printf("Quiting...");
		exit(1);
	}
}
#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <map>

namespace SMDB {
	//TODO: make this non windows specific
	void error(std::string str) {
		SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE), 0x0C);
		printf("%s\nFatal error...\nPress any key to quit...\n", str.c_str());
		_getch();
		printf("Quiting...");
		exit(1);
	}
};
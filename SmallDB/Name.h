#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <map>

namespace SMDB {
	class Name {
		char length;
	public:
		std::string name;

		void save(std::ofstream* file);
		Name();
		Name(std::ifstream* file);
		Name(std::string _name);
	};
}
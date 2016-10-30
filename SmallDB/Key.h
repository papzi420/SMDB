#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <map>
#include "Name.h"
#include "Enums.h"
namespace SMDB {
	class Key {
	public:
		Name name;
		Enums::TypeSignature type;

		void save(std::ofstream* file);
		Key(std::ifstream* file);
	};
}
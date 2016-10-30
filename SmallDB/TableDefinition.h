#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <map>
#include "Name.h"
#include "Key.h"
#include "Misc.h"
#include "Enums.h"

namespace SMDB {
	class TableDefinition {
	static char signature;
	public:
		Name name;
		std::vector<Key> keys;
		void save(std::ofstream* file);

		TableDefinition(std::ifstream* file);
		TableDefinition(Name _name);
		TableDefinition(std::vector<Key> _keys, Name _name);
	};
	
}
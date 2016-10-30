#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <map>
#include "TableDefinition.h"

namespace SMDB {

	class File {
	private:
		/* low level vars*/
		char tableDefintionsEnd;
	public:
		std::string signature;
		std::vector<TableDefinition> tableDefintions;
		std::ifstream* file;

		File();
		File(std::ifstream inputFile);

		void save(std::ofstream outputFile);
	};
}

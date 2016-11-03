	#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <map>
#include "Name.h"
#include "Misc.h"
#include "Row.h"
#include "TableDefinition.h"
namespace SMDB {
	class Row;
	class DataDefinition
	{
	public:
		static char signature;
		Name name;
		std::vector<Row> rows;

		DataDefinition(std::ifstream* file, std::vector<TableDefinition> tableDefinitions);
		DataDefinition(Name _name);
		void save(std::ofstream* file);
	};
}

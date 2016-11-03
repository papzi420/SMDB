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
#include "Enums.h"
#include "TableDefinition.h"
namespace SMDB {
	class RowItem {
	public:
		Enums::TypeSignature type;
		int number;
		std::string text;
		RowItem(std::ifstream* file, Enums::TypeSignature _type);
		RowItem(Enums::TypeSignature _type, std::string _text);
		RowItem(Enums::TypeSignature _type, int _number);
		void save(std::ofstream* file);
	};
	class Row
	{
	public:
		std::vector<RowItem> data;

		Row(std::ifstream* file, TableDefinition tableDefinition);
		Row();
		void write(std::ofstream* file);
		
	};
}
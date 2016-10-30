// SmallDB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "SMDB.h"
#include "TableDefinition.h"
#include "key.h"
int main()
{
	SMDB::File database = SMDB::File(std::ifstream("exampleDB.smdb"));
	for (SMDB::TableDefinition &tableDefintion : database.tableDefintions) {
		printf("%s: ", tableDefintion.name.name.c_str());
		for (SMDB::Key &key : tableDefintion.keys) {
			printf("{%s %s}, ", SMDB::Enums::enumToText[key.type].c_str(), key.name.name.c_str());
		}
		printf("\n");
	}
	database.save(std::ofstream("output.smdb"));
	_getch();
    return 0;
}


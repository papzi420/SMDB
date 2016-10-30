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
	//Create a new empty database
	SMDB::File database = SMDB::File();
	
	//Add a table called "Users"
	database.tableDefintions.push_back(SMDB::TableDefinition(SMDB::Name("Users")));
	//Add keys called "Username", "Hash" and "Salt" containing a string
	database.tableDefintions[0].keys.push_back(SMDB::Key(SMDB::Name("Username"), SMDB::Enums::string));
	database.tableDefintions[0].keys.push_back(SMDB::Key(SMDB::Name("Hash"), SMDB::Enums::string));
	database.tableDefintions[0].keys.push_back(SMDB::Key(SMDB::Name("Salt"), SMDB::Enums::string));
	
	//Add a table called "movies"
	database.tableDefintions.push_back(SMDB::TableDefinition(SMDB::Name("Movies")));
	//Add keys called "Title" and "Date" containing a string and a date
	database.tableDefintions[1].keys.push_back(SMDB::Key(SMDB::Name("Title"), SMDB::Enums::string));
	database.tableDefintions[1].keys.push_back(SMDB::Key(SMDB::Name("Date"), SMDB::Enums::date));

	for (SMDB::TableDefinition &tableDefintion : database.tableDefintions) {
		printf("%s: ", tableDefintion.name.name.c_str());
		for (SMDB::Key &key : tableDefintion.keys) {
			printf("{%s %s}, ", SMDB::Enums::enumToText[key.type].c_str(), key.name.name.c_str());
		}
		printf("\n");
	}
	//Save the database to output.smdb
	database.save(std::ofstream("output.smdb"));
	_getch();
    return 0;
}


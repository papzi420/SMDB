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
	database.tableDefintions[0].keys.push_back(SMDB::Key(SMDB::Name("Username"), SMDB::Enums::text));
	database.tableDefintions[0].keys.push_back(SMDB::Key(SMDB::Name("Hash"), SMDB::Enums::text));
	database.tableDefintions[0].keys.push_back(SMDB::Key(SMDB::Name("Salt"), SMDB::Enums::text));
	
	//Add a table called "movies"
	database.tableDefintions.push_back(SMDB::TableDefinition(SMDB::Name("Movies")));
	//Add keys called "Title" and "Date" containing a string and a date
	database.tableDefintions[1].keys.push_back(SMDB::Key(SMDB::Name("Title"), SMDB::Enums::text));
	database.tableDefintions[1].keys.push_back(SMDB::Key(SMDB::Name("Date"), SMDB::Enums::date));
	//Add data for the tables "Users"
	database.dataDefintions.push_back(SMDB::DataDefinition(SMDB::Name("Users")));
	//Creating a new row
	database.dataDefintions[0].rows.push_back(SMDB::Row());
	//Adding the actual data
	SMDB::RowItem item = SMDB::RowItem(SMDB::Enums::text, "banan");
	database.dataDefintions[0].rows[0].data.push_back(item);
	SMDB::RowItem item2 = SMDB::RowItem(SMDB::Enums::text, "baasdfasdfnan");
	database.dataDefintions[0].rows[0].data.push_back(item2);
	SMDB::RowItem item3 = SMDB::RowItem(SMDB::Enums::text, "adfadsf");
	database.dataDefintions[0].rows[0].data.push_back(item3);
	
	for (SMDB::TableDefinition &tableDefinition : database.tableDefintions) {
		printf("%s: ", tableDefinition.name.name.c_str());
		for (SMDB::Key &key : tableDefinition.keys) {
			printf("{%s %s}, ", SMDB::Enums::enumToText[key.type].c_str(), key.name.name.c_str());
		}
		printf("\n");
	}

	for (SMDB::DataDefinition &dataDefinition : database.dataDefintions) {
		printf("Table %s:\n", dataDefinition.name.name.c_str());
		for (SMDB::Row &row : dataDefinition.rows) {
			printf("\tRow: ");
			for (SMDB::RowItem &rowItem : row.data) {
				printf("%s, ", rowItem.text.c_str());
			}
			printf("\n");
		}
	}
	//Save the database to output.smdb
	database.save(std::ofstream("output.smdb"));
	_getch();
    return 0;
}


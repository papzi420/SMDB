#include "stdafx.h"
#include "DataDefinition.h"

namespace SMDB {
	/*
	signature: "D" 1 byte
	name: Name of the tabledefinition for the data
	rows: rows seperated by 1's
	*/
	DataDefinition::DataDefinition(std::ifstream* file, std::vector<TableDefinition> tableDefinitions)
	{
		char _ = ' ';
		file->read(&_, 1);
		if (_ == signature) {
			printf("Found file signature\n");
		}
		else {
			SMDB::Misc::error("malformed DB...\nSignature for dataDefinition was wrong...");
		}

		name = Name(file);

		TableDefinition selectedTableDefinition = TableDefinition(name);
		for (TableDefinition &tableDefinition : tableDefinitions) {
			if (tableDefinition.name.name == name.name) {
				selectedTableDefinition = tableDefinition;
			}
		}

		/* Read the row */
		char oneMore = ' ';
		file->read(&oneMore, 1);

		while (oneMore) {
			rows.push_back(Row(file, selectedTableDefinition));
			file->read(&oneMore, 1);
		}
	}

	DataDefinition::DataDefinition(Name _name)
	{
		name = _name;
	}

	void DataDefinition::save(std::ofstream * file)
	{
		file->write(&signature, 1);
		name.save(file);
		for (Row row : rows) {
			file->write(new char[1] {1}, 1);
			row.write(file);
		}
		file->write(new char[1]{ 0 }, 1);
	}

	char DataDefinition::signature = 'D';
}

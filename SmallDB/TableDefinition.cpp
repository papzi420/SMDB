#include "stdafx.h"
#include "TableDefinition.h"

namespace SMDB {
	TableDefinition::TableDefinition()
	{
	}

	TableDefinition::TableDefinition(std::ifstream* file) {
		file->read(&signature, 1);
		if (signature == 'T') {
			printf("Found file signature\n");
		}
		else {
			SMDB::Misc::error("malformed DB...\nSignature for tableDefinition was wrong...");
		}
		std::cout << "reading name\n";
		name = Name(file);
		std::cout << "read name\n";

		/* Read the keys */
		char oneMore = ' ';
		file->read(&oneMore, 1);
		while (oneMore) {
			keys.push_back(Key(file));
			file->read(&oneMore, 1);
		}
	}

	TableDefinition::TableDefinition(Name _name)
	{
		name = _name;
	}

	TableDefinition::TableDefinition(std::vector<Key> _keys, Name _name)
	{
		keys = _keys;
		name = _name;
	}

	void TableDefinition::save(std::ofstream* file) {
		file->write(&signature, 1);
		name.save(file);
		for (unsigned int i = 0; i < keys.size(); i++) {
			file->write(new char[1]{ 1 }, 1);
			Key key = keys[i];
			key.save(file);
		}
		file->write(new char[1]{ 0 }, 1);
	}
	char TableDefinition::signature = 'T';
}
#include "stdafx.h"
#include "SMDB.h"

namespace SMDB {
	void error(std::string str) {
		SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE), 0x0C);
		printf("%s\nFatal error...\nPress any key to quit...\n", str.c_str());
		_getch();
		printf("Quiting...");
		exit(1);
	}

	File::File(std::ifstream inputFile)
	{
		file = &inputFile;

		signature = std::string(4, ' ');
		file->read(&signature.front(), 4);

		if (signature == "SMDB") {
			printf("Found file signature\n");
		}
		else {
			error("malformed DB...\nGot signature: " + signature + ", expected: SMDB");
		}

		char oneMore = true;
		while (oneMore) {
			std::cout << "found new table def\n";
			tableDefintions.push_back(TableDefinition(file));
			file->read(&oneMore, 1);
		}
		file->close();
	}

	void File::save(std::ofstream outputFile) {
		outputFile.write("SMDB", 4);
		for (SMDB::TableDefinition &tableDefintion : tableDefintions) {
			tableDefintion.save(&outputFile);
		}
		outputFile.close();
	}
}
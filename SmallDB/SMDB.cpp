#include "stdafx.h"
#include "SMDB.h"

namespace SMDB {
	File::File(std::ifstream inputFile)
	{
		file = &inputFile;

		signature = std::string(4, ' ');
		file->read(&signature.front(), 4);

		if (signature == "SMDB") {
			printf("Found file signature\n");
		}
		else {
			SMDB::Misc::error("malformed DB...\nGot signature: " + signature + ", expected: SMDB");
		}

		char oneMore = ' ';
		inputFile.read(&oneMore, 1);
		while (oneMore) {
			std::cout << "found new table def\n";
			tableDefintions.push_back(TableDefinition(file));
			inputFile.read(&oneMore, 1);
		}
		file->close();
	}

	File::File() {

	}
	void File::save(std::ofstream outputFile) {
		outputFile.write("SMDB", 4);
		for (unsigned int i = 0; i < tableDefintions.size(); i++) {
			outputFile.write(new char[1]{ 1 }, 1);
			TableDefinition tableDefintion = tableDefintions[i];
			tableDefintion.save(&outputFile);
		}
		outputFile.write(new char[1]{ 0 }, 1);
		outputFile.close();
	}
}
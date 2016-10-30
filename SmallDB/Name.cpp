#include "stdafx.h"
#include "Name.h"

namespace SMDB {
	Name::Name() {
		length = 0;
		name = "";
	}

	Name::Name(std::string _name) {
		length = _name.length();
		name = _name;
	}

	Name::Name(std::ifstream* file) {
		file->read(&length, 1);
		name = std::string(length, ' ');
		file->read(&name.front(), length);
	}

	void Name::save(std::ofstream* file) {
		char length = name.length();
		file->write(&length, 1);
		file->write(name.c_str(), sizeof(char)*name.size());
	}
}
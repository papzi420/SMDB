#include "stdafx.h"
#include "Key.h"

namespace SMDB {

	Key::Key(std::ifstream* file) {
		name = Name(file);
		char output = ' ';
		file->read(&output, 1);
		type = (Enums::TypeSignature) output;
	}

	Key::Key(Name _name, Enums::TypeSignature _type)
	{
		name = _name;
		type = _type;
	}

	void Key::save(std::ofstream* file) {
		name.save(file);
		file->write(new char[1]{ (char)type }, 1);
	}
}
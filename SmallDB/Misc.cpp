#include "stdafx.h"
#include "misc.h"

namespace SMDB {
	//TODO: Make this cross-platform
	void Misc::error(std::string str) {
#ifdef _WIN32
		SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE), 0x0C);
		printf("%s\nFatal error...\nPress any key to quit...\n", str.c_str());
		SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE), 0x0F);
#else
		printf("%s\e[91m\nFatal error...\nPress any key to quit...\n\e[39m", str.c_str());
#endif
		_getch();
		printf("Quiting...");
		exit(1);
	}
	uint32_t StandardTypes::readUInt(std::ifstream* file)
	{
		unsigned int value = 0;
		char* _ = new char[4];
		file->read(_, 4);
		value = _[3] << 24;
		value |= _[2] << 16;
		value |= _[1] << 8;
		value |= _[0];
		return value;
	}

	void StandardTypes::writeUInt(std::ofstream* file, uint32_t number)
	{
		char* _ = new char[4];
		_[0] = number & 0xFF;
		_[1] = number & 0xFF00;
		_[2] = number & 0xFF0000;
		_[3] = number & 0xFF000000;
		file->write(_, 4);
	}

	uint64_t StandardTypes::readUInt64(std::ifstream* file) {
		uint64_t value = 0;
		char* _ = new char[8];
		file->read(_, 8);
		value = _[7] << 56;
		value |= _[6] << 48;
		value |= _[5] << 40;
		value |= _[4] << 32;
		value |= _[3] << 24;
		value |= _[2] << 16;
		value |= _[1] << 8;
		value |= _[0];
		return value;
	}

	void StandardTypes::writeUInt(std::ofstream * file, uint64_t number)
	{
		char* _ = new char[8];
		_[0] = number & 0xFF;
		_[1] = number & 0xFF00;
		_[2] = number & 0xFF0000;
		_[3] = number & 0xFF000000;
		_[4] = number & 0xFF00000000;
		_[5] = number & 0xFF0000000000;
		_[6] = number & 0xFF000000000000;
		_[6] = number & 0xFF00000000000000;
		file->write(_, 8);
	}
}
#pragma once

#include <string>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <cstdint>
#ifdef _WIN32
	#include <windows.h>
#endif
namespace SMDB {
	class Misc
	{
	public:
		static void error(std::string err);
	};
	class StandardTypes {
	public:
		static uint32_t readUInt(std::ifstream* file);
		static void writeUInt(std::ofstream* file, uint32_t number);
		static uint64_t readUInt64(std::ifstream * file);
		static void writeUInt(std::ofstream* file, uint64_t number);
	};
}
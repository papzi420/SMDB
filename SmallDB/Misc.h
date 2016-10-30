#pragma once

#include <string>
#include <conio.h>
#ifdef _WIN32
	#include <windows.h>
#endif
namespace SMDB {
	class Misc
	{
	public:
		static void error(std::string err);
	};
}
#pragma once
#include <string>
namespace SMDB {
	class Enums {
	public:
		enum TypeSignature {
			string,
			date
		};
		static const std::string enumToText[];
	};
}
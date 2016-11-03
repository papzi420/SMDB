#pragma once
#include <string>
namespace SMDB {
	class Enums {
	public:
		enum TypeSignature {
			text,
			date
		};
		static const std::string enumToText[];
	};
}
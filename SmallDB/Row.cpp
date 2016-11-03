#include "stdafx.h"
#include "Row.h"

namespace SMDB{
	/*
	the type data with no seperation
	*/
	Row::Row(std::ifstream * file, TableDefinition tableDefinition)
	{
		for (Key &key : tableDefinition.keys) {
			data.push_back(RowItem(file, key.type));
		}
	}
	Row::Row()
	{
	}
	void Row::write(std::ofstream * file)
	{
		for (RowItem &item : data) {
			item.save(file);
		}
	}
	/* 
	RowItem 
	*/
	RowItem::RowItem(std::ifstream * file, Enums::TypeSignature _type)
	{
		type = _type;
		if (type == Enums::text) {
			int length = StandardTypes::readUInt(file);
			text = std::string(length, ' ');
			file->read(&text.front(), length);
		}

	}

	RowItem::RowItem(Enums::TypeSignature _type, std::string _text)
	{
		type = _type;
		text = _text;
	}

	RowItem::RowItem(Enums::TypeSignature _type, int _number)
	{
		type = _type;
		number = _number;
	}

	void RowItem::save(std::ofstream * file)
	{
		if (type == Enums::text) {
			StandardTypes::writeUInt(file, text.length());
			file->write(text.c_str(), text.length());
		}
	}
}
#pragma once
#include "stdafx.h"

enum class Types
{
	String,
	Bool,
	Double,
	Null,
};

bool const operator==(Types const &type1, std::string type2)
{
	if (type1 == Types::Bool)
		return type2 == "bool";
	else if (type1 == Types::String)
		return type2 == "string";
	else if (type1 == Types::Null)
		return type2 == "null";
	else if (type1 == Types::Double)
		return type2 == "double";
	
	return false;
}


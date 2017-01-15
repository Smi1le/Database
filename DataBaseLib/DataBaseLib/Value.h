#pragma once
#include <string>

class CValue
{
public:
	CValue(std::string const & value = "null");
	void ReplaceValue(std::string const & value);
	void RemoveValue();
	std::string GetValue() const;

private:
	std::string m_value;
	
};


#pragma once
#include <string>

class CValue
{
public:
	CValue() = default;
	CValue(std::string const & value);
	void ReplaceValue(std::string const & value);
	void RemoveValue();
	std::string GetValue() const;

private:
	std::string m_value;
	
};


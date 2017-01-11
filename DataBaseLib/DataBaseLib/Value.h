#pragma once
#include <string>

class CValue
{
public:
	CValue(std::string const & value, std::string const & type);
	void ReplaceValue(std::string const & value);
	void RemoveValue();
	std::string GetValue() const;

	std::string GetType() const;
private:
	std::string m_value;
	std::string m_type; // TODO: возможно не нужен будет
};


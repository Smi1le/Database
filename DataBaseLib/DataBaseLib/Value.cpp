#include "stdafx.h"
#include "Value.h"



CValue::CValue(std::string const & value, std::string const & type = "norm")
	: m_value(value)
	, m_type(type)
{
}

void CValue::ReplaceValue(std::string const & value)
{
	m_value = value;
}

void CValue::RemoveValue()
{
	m_value.clear();
}

std::string CValue::GetValue() const
{
	return m_value;
}

std::string CValue::GetType() const
{
	return m_type;
}

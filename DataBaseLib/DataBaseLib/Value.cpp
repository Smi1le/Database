#include "stdafx.h"
#include "Value.h"



CValue::CValue(std::string const & value)
	: m_value(value)
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

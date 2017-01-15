#include "stdafx.h"
#include "Value.h"



CValue::CValue(std::string const & value)
{
	try
	{
		m_value = value;
	}
	catch (...)
	{
		m_value = "null";
	}
}

void CValue::ReplaceValue(std::string const & value)
{
	try
	{
		m_value = value;
	}
	catch (...)
	{
		throw;
	}
	
}

void CValue::RemoveValue()
{
	m_value.clear();
}

std::string CValue::GetValue() const
{
	return m_value;
}

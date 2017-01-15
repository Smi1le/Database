#include "stdafx.h"
#include "Note.h"


void CNote::AddColumn(size_t idColumn, CValue const & value)
{
	try
	{
		m_note.insert(std::pair<size_t, CValue>(idColumn, value));
	}
	catch (...)
	{
		throw;
	}
}

void CNote::RemoveNote()
{
	m_note.clear();
}

void CNote::RemoveColumn(size_t columnId)
{
	try
	{
		m_note.erase(columnId);
	}
	catch (...)
	{
		throw std::runtime_error("failed to remove column");
	}
	
}

size_t CNote::GetSize() const
{
	return m_note.size();
}

void CNote::UpdateNote(size_t column, std::string const & value)
{
	try
	{
		m_note.at(column).ReplaceValue(value);
	}
	catch (std::out_of_range &ex)
	{
		throw ex;
	}
}

void CNote::Show()
{
	for (auto const &el : m_note)
	{
		std::cout << el.first << " : " << el.second.GetValue() << std::endl;
	}
}

CValue CNote::GetColumnValue(size_t column) const
{
	try
	{
		return m_note.at(column);
	}
	catch (std::out_of_range &ex)
	{
		throw ex;
	}
	
}

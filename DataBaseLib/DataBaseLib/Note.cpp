#include "stdafx.h"
#include "Note.h"


void CNote::AddColumn(size_t idColumn, CValue const & value)
{
	m_note.insert(std::pair<size_t, CValue>(idColumn, value));
}

void CNote::RemoveNote()
{
	m_note.clear();
}

void CNote::RemoveColumn(size_t columnId)
{
	m_note.erase(columnId);
}

void CNote::UpdateNote(size_t column, std::string const & value)
{
	m_note.at(column).ReplaceValue(value);
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
	return m_note.at(column);
}

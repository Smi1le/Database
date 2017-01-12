#include "stdafx.h"
#include "Note.h"

CNote::CNote(std::vector<std::string> const & columnsName)
{
	for (auto const &el : columnsName)
	{
		m_note.insert(std::pair<std::string, CValue>(el, CValue()));
	}
}

void CNote::AddColumn()
{
	// TODO: create method
}

void CNote::RemoveNote()
{
	m_note.clear();
}

void CNote::RemoveColumn(std::string const & columnName)
{
	m_note.erase(columnName);
}

void CNote::UpdateNote(std::string const & columnName, std::string const & value)
{
	m_note.at(columnName).ReplaceValue(value);
}

void CNote::Show()
{
	for (auto const &el : m_note)
	{
		std::cout << el.first << " : " << el.second.GetValue() << std::endl;
	}
	std::cout << "\n\n\n\n";
}

CValue CNote::GetColumnValue(std::string const & columnName) const
{
	return m_note.at(columnName);
}

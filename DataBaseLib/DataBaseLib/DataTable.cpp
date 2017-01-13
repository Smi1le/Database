#include "stdafx.h"
#include "DataTable.h"


void CDataTable::RemoveNote()
{
}

void CDataTable::RemoveColumn(std::string const & columnName)
{
	/*auto columnIndex = m_columnNames.at(columnName);
	for (auto & row : m_table)
	{
		row.RemoveColumn(columnIndex.id);
	}*/
}

void CDataTable::Update()
{
}

void CDataTable::AddNote(CNote const &note)
{
	m_table.push_back(note);
}

CNote CDataTable::GetNote(size_t row) const
{
	return m_table.at(row);
}

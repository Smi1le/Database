#include "stdafx.h"
#include "DataTable.h"


CDataTable::CDataTable(std::string const & name, ColumnsNames const & columns)
	: m_name(name)
	, m_columnNames(columns)
{
}

void CDataTable::RemoveNote(size_t row)
{
	if (m_table.size() < row)
	{
		//TODO: exception
		return;
	}
	auto position = m_table.begin() + row;
	m_table.erase(position, position + 1);
}

void CDataTable::RemoveColumn(std::string const & columnName)
{
	auto column = m_columnNames.at(columnName);
	
	for (auto & row : m_table)
	{
		row.RemoveColumn(column.id);
	}
}

void CDataTable::RenameColumn(std::string const & columnName, std::string const & newColumnName)
{
	if (m_columnNames.find(newColumnName) != m_columnNames.end())
	{
		std::cout << "This name exist" << std::endl;
		return;
	}
	auto column = m_columnNames.at(columnName);
	m_columnNames.erase(columnName);
	m_columnNames.insert(std::pair<std::string, SColumn>(newColumnName, column));
}

void CDataTable::AddNote(CNote const &note)
{
	m_table.push_back(note);
}

void CDataTable::AddEmptyColumn(std::string const & columnName, std::string const & type)
{
	if (m_columnNames.find(columnName) != m_columnNames.end())
	{
		return;
	}
	auto position = columnName.size();
	m_columnNames.insert(std::pair <std::string, SColumn>(columnName, SColumn(position, type)));

	for (auto & note : m_table)
	{
		note.AddColumn(position, CValue());
	}
}

CNote CDataTable::GetNote(size_t row) const
{
	return m_table.at(row);
}

void CDataTable::SetName(std::string const & name)
{
	m_name = name;
}

std::string CDataTable::GetName() const
{
	return m_name;
}

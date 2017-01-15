#include "stdafx.h"
#include "DataTable.h"


CDataTable::CDataTable(std::string const & name, ColumnsNames const & columns)
{
	try
	{
		m_name = name;
		m_columnNames = columns;
	}
	catch (...)
	{
		m_name = "";
		m_columnNames = ColumnsNames();
		throw std::runtime_error("failed to initialize data table");
	}
}

void CDataTable::RemoveNote(size_t row)
{
	auto lastTable = m_table;
	try
	{
		if (m_table.size() <= row)
		{
			throw std::runtime_error("failed to remove note");
		}
		auto position = m_table.begin() + row;
		m_table.erase(position, position + 1);
	}
	catch (std::runtime_error & ex)
	{
		m_table = lastTable;
		throw ex;
	}
}

void CDataTable::RemoveColumn(std::string const & columnName)
{
	auto columnNames = m_columnNames;
	try
	{
		auto column = m_columnNames.at(columnName);

		for (auto & row : m_table)
		{
			row.RemoveColumn(column.id);
		}
	}
	catch (std::runtime_error &ex)
	{
		m_columnNames = columnNames;
	}
}

void CDataTable::RenameColumn(std::string const & columnName, std::string const & newColumnName)
{
	auto columnNames = m_columnNames;
	try
	{
		if (m_columnNames.find(newColumnName) != m_columnNames.end())
		{
			throw;
		}
		auto column = m_columnNames.at(columnName);
		m_columnNames.erase(columnName);
		m_columnNames.emplace(std::pair<std::string, SColumn>(newColumnName, column));
	}
	catch (...)
	{
		m_columnNames = columnNames;
		throw std::runtime_error("failed to rename colomn");
	}
}

void CDataTable::AddNote(CNote const &note)
{
	auto table = m_table;
	try
	{
		m_table.push_back(note);
	}
	catch (...)
	{
		m_table = table;
		throw std::runtime_error("failed to add note");
	}
}

void CDataTable::AddEmptyColumn(std::string const & columnName, std::string const & type)
{
	auto table = m_table;
	try
	{
		if (m_columnNames.find(columnName) != m_columnNames.end())
		{
			throw std::invalid_argument("column name not found");
		}
		auto position = columnName.size();
		m_columnNames.emplace(std::pair<std::string, SColumn>(columnName, SColumn(position, type)));

		for (auto & note : m_table)
		{
			note.AddColumn(position, CValue());
		}
	}
	catch (...)
	{
		m_table = table;
		throw;
	}
}

CNote CDataTable::GetNote(size_t row) const
{
	if (row >= m_table.size())
	{
		throw std::out_of_range("Out of range");
	}
	return m_table[row];
}


void CDataTable::SetName(std::string const &name)
{
	auto lastName = m_name;
	try
	{
		m_name = name;
	}
	catch (...)
	{
		m_name = lastName;
		throw std::runtime_error("failed to set a new name");
	}
}

void CDataTable::AddColumnsNames(std::vector<Column> const & columns)
{
	auto lastColumnNames = m_columnNames;
	try
	{
		for (size_t i = 0; i != columns.size(); ++i)
		{
			auto column = columns[i];
			m_columnNames.emplace(std::pair<std::string, SColumn>(column.first, SColumn(i, column.second)));
		}
	}
	catch (...)
	{
		m_columnNames = lastColumnNames;
		throw std::runtime_error("failed to add new columns names");
	}
}


size_t CDataTable::GetNotesCount() const
{
	return m_table.size();
}

size_t CDataTable::GetColumnCount() const
{
	return m_columnNames.size();
}

std::string CDataTable::GetName() const
{
	return m_name;
}

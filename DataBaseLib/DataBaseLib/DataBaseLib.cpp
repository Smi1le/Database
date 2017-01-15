#include "stdafx.h"
#include "DataBaseLib.h"



void CDataBaseLib::LoadTableFromFile(std::string const & data)
{
	CParser parser;
	auto table = parser.Parse(data);
	m_tables.emplace(table.GetName(), table);
}

void CDataBaseLib::LoadTablesFromFiles(std::vector<std::string> const & paths)
{
	for (auto const & path : paths)
	{
		LoadTableFromFile(path);
	}
}

void CDataBaseLib::DeleteTable(std::string const & tableName)
{
	auto success = m_tables.erase(tableName);
	std::cout << "Table removed" << std::endl;
}

void CDataBaseLib::AddTable(std::string const & tableName, std::vector<Column> const & columns)
{
	ColumnsNames columNames;
	for (size_t index = 0; index < columns.size(); ++index)
	{
		auto column = columns[index];
		SColumn col(index, column.second);
		columNames.insert(std::pair<std::string, SColumn>(column.first, col));
	}
	CDataTable table(tableName, columNames);
	m_tables.emplace(tableName, table);
}

CDataTable CDataBaseLib::GetTable(std::string const & tableName)
{
	return m_tables[tableName];
}

void CDataBaseLib::RenameTable(std::string const & tableName, std::string const & newTableName)
{
	if (m_tables.find(newTableName) != m_tables.end())
	{
		std::cout << "This name exist" << std::endl;
		return;
	}
	auto table = m_tables[tableName];
	table.SetName(newTableName);
	m_tables.erase(tableName);
	m_tables.emplace(newTableName, table);
}
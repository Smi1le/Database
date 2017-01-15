#include "stdafx.h"
#include "DataBaseLib.h"



void CDataBaseLib::LoadTableFromFile(std::string const & data)
{
	CParser parser;
	auto table = parser.Parse(data);
	m_tables.emplace(std::pair<std::string, CDataTable>(table.GetName(), table));
}

void CDataBaseLib::DeleteTable(std::string const & tableName)
{
	if (!HasTable(tableName))
	{
		throw std::invalid_argument("Can't remove not exist table");
	}
	auto success = m_tables.erase(tableName);
	std::cout << "Table removed" << std::endl;
}

void CDataBaseLib::AddTable(std::string const & tableName, std::vector<Column> const & columns)
{
	if (HasTable(tableName))
	{
		throw std::invalid_argument("Table exist " + tableName);
	}
	ColumnsNames columNames;
	for (size_t index = 0; index < columns.size(); ++index)
	{
		auto column = columns[index];
		SColumn col(index, column.second);
		columNames.emplace(std::pair<std::string, SColumn>(column.first, col));
	}
	CDataTable table(tableName, columNames);
	m_tables.emplace(std::pair<std::string, CDataTable>(tableName, table));
	std::cout << "Table created" << std::endl;
}

CDataTable CDataBaseLib::GetTable(std::string const & tableName)
{
	if (!HasTable(tableName))
	{
		throw std::invalid_argument("Table not exist " + tableName);
	}
	return m_tables[tableName];
}

void CDataBaseLib::RenameTable(std::string const & tableName, std::string const & newTableName)
{
	if (HasTable(newTableName))
	{
		std::cout << "This name exist" << std::endl;
		return;
	}
	auto table = m_tables[tableName];
	table.SetName(newTableName);
	m_tables.erase(tableName);
	m_tables.emplace(newTableName, table);
}

bool CDataBaseLib::HasTable(std::string const & tableName)
{
	return m_tables.find(tableName) != m_tables.end();
}

#include "stdafx.h"
#include "DataBaseLib.h"

void CDataBaseLib::LoadTableFromFile(std::string const & data)
{
	auto table = m_parser.Parse(data);
	m_tables.insert(std::pair<std::string, CDataTable>(table.GetName(), table));
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
	success > 0 ? std::cout << "Table removed" << std::endl : std::cout << "Table not exist: " + tableName << std::endl;
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
}

CDataTable CDataBaseLib::GetTable(std::string const & tableName) const
{
	return m_tables.at(tableName);
}


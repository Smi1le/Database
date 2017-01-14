#include "stdafx.h"
#include "DataBaseLib.h"


DataBaseLib::DataBaseLib()
{
}

void DataBaseLib::LoadTableFromFile(std::string const & data)
{
	auto table = m_parser.Parse(data);
}

void DataBaseLib::LoadTableFromFiles(std::vector<std::string> const & paths)
{
	for (auto const & path : paths)
	{
		m_parser.Parse(path);
	}
}

void DataBaseLib::DeleteTable(std::string const & tableName)
{
	auto success = m_tables.erase(tableName);
	success > 0 ? std::cout << "Table removed" << std::endl : std::cout << "Table not exist: " + tableName << std::endl;
}

void DataBaseLib::AddTable()
{
	// TODO: скорей всего будут поступать данные из вне и в этом методе формироваться таблица
}

CDataTable DataBaseLib::GetTable(std::string const & tableName) const
{
	return m_tables.at(tableName);
}


#include "stdafx.h"
#include "DataBaseLib.h"


DataBaseLib::DataBaseLib()
{
}

void DataBaseLib::LoadTableFrom(std::string const & pathTemplate, std::string const & data)
{
}

void DataBaseLib::DeleteTable(std::string const & tableName)
{
}

void DataBaseLib::AddTable()
{
}

CDataTable DataBaseLib::GetTable(std::string const & tableName) const
{
	return m_tables.at(tableName);
}


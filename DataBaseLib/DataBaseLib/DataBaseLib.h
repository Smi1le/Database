#pragma once
#include <map>
#include <string>
#include "DataTable.h"


class DataBaseLib
{
public:
	DataBaseLib();
	void LoadTableFrom(std::string const & pathTemplate, std::string const & data);
	void DeleteTable(std::string const & tableName);
	void AddTable();
	CDataTable GetTable(std::string const & tableName) const;
private:
	std::map<std::string, CDataTable> m_tables;
};


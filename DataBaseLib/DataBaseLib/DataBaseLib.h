#pragma once
#include <map>
#include <string>
#include "DataTable.h"
#include "Parser.h"


class DataBaseLib
{
public:
	DataBaseLib();
	void LoadTableFromFile(std::string const & data);
	void LoadTableFromFiles(std::vector<std::string> const & paths);
	void DeleteTable(std::string const & tableName);
	void AddTable();
	CDataTable GetTable(std::string const & tableName) const;
private:
	std::map<std::string, CDataTable> m_tables;
	CParser m_parser;
};


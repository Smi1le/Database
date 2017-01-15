#pragma once
#include <map>
#include <string>
#include "DataTable.h"
#include "Parser.h"


class CDataBaseLib
{
public:
	CDataBaseLib() = default;
	void LoadTableFromFile(std::string const & path);

	void DeleteTable(std::string const & tableName);
	void AddTable(std::string const & tableName, std::vector<Column> const & columns);
	CDataTable GetTable(std::string const & tableName);

	void RenameTable(std::string const & tableName, std::string const & newTableName);
private:
	bool HasTable(std::string const & tableName);
private:
	std::map<std::string, CDataTable> m_tables;
};


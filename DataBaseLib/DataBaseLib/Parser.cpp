#include "stdafx.h"
//#include "DataTable.h"
#include "DataBaseLib.h"
#include "Parser.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>

#include "Note.h"

using namespace std;
using Table = std::vector<std::vector<std::string>>;


namespace
{
	CDataTable ConvertToNormForm(Table const &table, std::string const &tableName)
	{
		CDataTable newTable(tableName);
		vector<std::pair<string, string>> infos;
		for (size_t k = 0; k != table[0].size(); ++k)
		{
			infos.push_back(std::pair<std::string, std::string>(table[0][k], table[1][k]));
		}
		newTable.AddColumnsNames(infos);
		for (size_t i = 2; i != table.size(); ++i)
		{
			
			CNote newNote;
			for (size_t j = 0; j != table[i].size(); ++j)
			{
				auto columnName = table[0][j];
				auto value = table[i][j];
				newNote.AddColumn(j, value);

			}
			newTable.AddNote(newNote);
		}
		


		return newTable;
	}
}

CDataTable CParser::Parse(std::string const & fileName)
{
	
	std::vector<string> listDatabaseFiles = GetContentsFile(fileName);
	
	auto newDT = GetNewDataTable(listDatabaseFiles);

	std::cout << "Table name = " << newDT.GetName() << std::endl;
	return newDT;
}

std::vector<string> CParser::GetContentsFile(std::string const & fileName)
{
	std::ifstream inputFile(fileName);
	
	if (!inputFile.is_open())
	{
		throw std::invalid_argument("File not found");
	}

	std::vector<string> listDatabaseFiles;
	std::string pathToFile;
	while (getline(inputFile, pathToFile))
	{
		listDatabaseFiles.push_back(pathToFile);
	}
	return listDatabaseFiles;
}

CDataTable CParser::GetNewDataTable(std::vector<std::string> const & tableInfo)
{
	std::string tableName;
	Table table;
	
	for (size_t i = 0; i != tableInfo.size(); ++i)
	{
		if (i == 0)
		{
			tableName = tableInfo[i];
			continue;
		}
		
		vector<string> listValues;
		boost::split(listValues, tableInfo[i], boost::is_any_of(":"));
		table.insert(table.end(), listValues);
		/*if (i == 1)
		{
			std::vector<Column> columnsNames;
			for (size_t innerCount = 0; innerCount != table[1].size(); ++innerCount)
			{
				columnsNames.push_back(Column(table[1][innerCount], "gavno"));
			}
			lib->AddTable(tableName, columnsNames);
		}*/
	}

	return ConvertToNormForm(table, tableName);
}

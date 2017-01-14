#include "stdafx.h"
#include "DataTable.h"
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
	std::pair<std::string, CDataTable> ConvertToNormForm(Table const &table, std::string const &tableName)
	{
		CDataTable newTable(tableName, );
		
		for (size_t i = 1; i != table.size(); ++i)
		{
			
			CNote newNote = CNote();
			for (size_t j = 0; j != table[i].size(); ++j)
			{
				auto columnName = table[0][j];
				auto value = table[i][j];
				newNote.AddColumn(j, value);

			}
			newTable.AddNote(newNote);
		}



		return std::pair<std::string, CDataTable>(tableName, newTable);
	}
}

std::map<std::string, CDataTable> CParser::Parse(std::string const & fileName)
{
	
	std::vector<string> listDatabaseFiles = GetContentsFile(fileName);
	auto newDT = GetNewDataTable(listDatabaseFiles);
	
	for (auto const &el : listDatabaseFiles)
	{
		std::cout << "el = " << el << std::endl;
	}
	std::cout << "Table name = " << newDT.first << std::endl;
	for (size_t i = 0; i != listDatabaseFiles.size() - 2; ++i)
	{
		newDT.second.GetNote(i).Show();
	}
	std::map<std::string, CDataTable> table;
	return table;
}

std::vector<string> CParser::GetContentsFile(std::string const & fileName)
{
	std::ifstream inputFile(fileName);
	
	if (!inputFile.is_open())
	{
		std::cout << "File not found" << std::endl;
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

std::pair<std::string, CDataTable> CParser::GetNewDataTable(std::vector<std::string> const & tableInfo)
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
	}

	return ConvertToNormForm(table, tableName);
}

#include "stdafx.h"
//#include "DataTable.h"
#include "DataBaseLib.h"
#include "Parser.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>

#include "Note.h"
#include "Types.h"

namespace
{
	bool CheckTypes(std::vector<std::string> const &typesList)
	{
		size_t innerCount = 0;
		for (size_t i = 0; i != typesList.size(); ++i)
		{
			if (Types::Bool == typesList[i] || Types::String == typesList[i] ||
				Types::Double == typesList[i] || Types::Null == typesList[i])
			{
				++innerCount;
			}
			else
			{
				break;
			}
			
		}
		return innerCount == typesList.size();
	}
}

using namespace std;
using Table = std::vector<std::vector<std::string>>;


namespace
{
	CDataTable ConvertToNormForm(Table const &table, std::string const &tableName)
	{
		CDataTable newTable(tableName);
		vector<std::pair<string, string>> infos;

		if (table[0].size() != table[1].size())
			throw std::invalid_argument("number of names mismatch column with the number of types");
		else if (!CheckTypes(table[1]))
			throw std::invalid_argument("They were used the wrong type");


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
	try
	{
		std::vector<string> listDatabaseFiles = GetContentsFile(fileName);

		auto newDT = GetNewDataTable(listDatabaseFiles);
		//lib->AddTable(listDatabaseFiles[0], listDatabaseFiles[1]);
		/*for (auto const &el : listDatabaseFiles)
		{
			std::cout << "el = " << el << std::endl << std::endl;
		}
		std::cout << "Table name = " << newDT.GetName() << std::endl;
		newDT.Show();*/
		return newDT;
	}
	catch (...)
	{
		throw;
	}
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
	try
	{
		std::string tableName;
		Table table;
		for (size_t i = 0; i != tableInfo.size(); ++i)
		{
			vector<string> listValues;
			boost::split(listValues, tableInfo[i], boost::is_any_of(":"));
			if (i == 0)
			{
				if (listValues.size() == 1)
					tableName = tableInfo[i];
				else
					throw std::invalid_argument("Имя таблицы не было найдено");
			}
			else
			{
				table.insert(table.end(), listValues);
			}
		}

		return ConvertToNormForm(table, tableName);
	}
	catch (...)
	{
		throw;
	}
}

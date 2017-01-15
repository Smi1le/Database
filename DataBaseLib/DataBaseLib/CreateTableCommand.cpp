#include "stdafx.h"
#include "CreateTableCommand.h"
#include <boost/algorithm/string.hpp>

CCreateTableCommand::CCreateTableCommand(CDataBaseLib & lib)
	: CAbstractMetaCommand(lib)
{
	SetDelimeter("--> ");
}

void CCreateTableCommand::DoExecute(std::string const & inputStr)
{
	std::vector<std::string> args;
	boost::split(args, inputStr, boost::is_any_of(" "));
	if (args.size() < 2)
	{
		std::cout << "unknown command" << std::endl;
		return;
	}
	else if (args[0] == "name")
	{
		m_tableName = args[1];
	}
	else if (args[0] == "addColumn" && args.size() == 3)
	{
		auto nameColumn = args[1];
		auto type = args[2];
		m_columns.emplace_back(Column(nameColumn, type));
	}
}

void CCreateTableCommand::Run()
{
	m_lib.AddTable(m_tableName, m_columns);
}

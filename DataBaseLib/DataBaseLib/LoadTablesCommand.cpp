#include "stdafx.h"
#include "LoadTablesCommand.h"
#include "CreateTableCommand.h"
#include <boost/algorithm/string.hpp>

CLoadTablesCommand::CLoadTablesCommand(CDataBaseLib & lib)
	: CAbstractMetaCommand(lib)
{
	SetDelimeter("-->");
}

void CLoadTablesCommand::DoExecute(std::string const & inputStr)
{
	std::vector<std::string> args;
	boost::split(args, inputStr, boost::is_any_of(" "));
	if (args.size() < 1)
	{
		std::cout << "unknown command" << std::endl;
		return;
	}
	else if (args[0] == "path")
	{
		m_lib.LoadTableFromFile(args[1]);
	}
	
}

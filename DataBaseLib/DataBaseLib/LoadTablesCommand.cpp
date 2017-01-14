#include "stdafx.h"
#include "LoadTablesCommand.h"

CLoadTablesCommand::CLoadTablesCommand(CDataBaseLib & lib)
	: CAbstractMetaCommand(lib)
{
	SetDelimeter("--> path: ");
}

void CLoadTablesCommand::DoExecute(std::string const & inputStr)
{
	m_lib.LoadTableFromFile(inputStr);
}

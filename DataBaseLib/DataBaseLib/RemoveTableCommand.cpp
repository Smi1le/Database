#include "stdafx.h"
#include "RemoveTableCommand.h"


CRemoveTableCommand::CRemoveTableCommand(CDataBaseLib & lib)
	: CAbstractCommand(lib)
{
	SetDelimeter("--> name: ");
}

void CRemoveTableCommand::DoExecute(std::string const & inputStr)
{
	m_lib.DeleteTable(inputStr);
}

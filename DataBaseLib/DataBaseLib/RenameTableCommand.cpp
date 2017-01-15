#include "stdafx.h"
#include "RenameTableCommand.h"

CRenameTableCommand::CRenameTableCommand(CDataBaseLib & lib)
	: CAbstractCommand(lib)
{
	SetDelimeter("-> input table name: ");
}

void CRenameTableCommand::DoExecute(std::string const & inputStr)
{	
	std::cout << "-> input new table name: ";
	std::string newName;
	std::cin >> newName;
	m_lib.RenameTable(inputStr, newName);
}

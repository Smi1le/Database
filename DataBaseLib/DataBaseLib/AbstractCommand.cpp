#include "stdafx.h"
#include "AbstractCommand.h"

CAbstractCommand::CAbstractCommand(CDataBaseLib & lib)
	: m_lib(lib)
	, m_delimeter("")
{
}

void CAbstractCommand::Execute()
{
	std::string inputStr;
	std::cout << m_delimeter;
	getline(std::cin, inputStr);
	DoExecute(inputStr);
}

void CAbstractCommand::SetDelimeter(std::string const & delimeter)
{
	m_delimeter = delimeter;
}

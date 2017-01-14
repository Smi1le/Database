#include "stdafx.h"
#include "AbstractMetaCommand.h"


CAbstractMetaCommand::CAbstractMetaCommand(CDataBaseLib & lib)
	: CAbstractCommand(lib)
{
}

void CAbstractMetaCommand::Execute()
{
	std::string inputStr;
	while ((std::cout << m_delimeter) && getline(std::cin, inputStr))
	{
		if (inputStr == "break")
		{
			return;
		}
		DoExecute(inputStr);
	}
}


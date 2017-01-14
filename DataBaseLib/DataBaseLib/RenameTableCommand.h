#pragma once
#include "AbstractCommand.h"

class CRenameTableCommand : public CAbstractCommand
{
public:
	CRenameTableCommand(CDataBaseLib & lib);

protected:
	void DoExecute(std::string const & inputStr) override;
};


#pragma once
#include "AbstractCommand.h"
#include "DataBaseLib.h"

class CRemoveTableCommand : public CAbstractCommand
{
public:
	CRemoveTableCommand(CDataBaseLib & lib);

protected:
	void DoExecute(std::string const & inputStr) override;
};


#pragma once
#include "AbstractMetaCommand.h"
#include "DataBaseLib.h"

class CLoadTablesCommand : public CAbstractMetaCommand
{
public:
	CLoadTablesCommand(CDataBaseLib & lib);

protected:
	void DoExecute(std::string const & inputStr) override;
	void Run() override {};
};


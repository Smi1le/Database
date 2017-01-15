#pragma once
#include "AbstractCommand.h"
#include "DataBaseLib.h"

class CShowTableCommand : public CAbstractCommand
{
public:
	CShowTableCommand(CDataBaseLib & lib);
protected:
	void DoExecute(std::string const & tableName) override;
};


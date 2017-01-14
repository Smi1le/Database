#pragma once
#include "AbstractCommand.h"
#include "DataBaseLib.h"

class CAbstractMetaCommand : public CAbstractCommand
{
public:
	CAbstractMetaCommand(CDataBaseLib & lib);
	virtual ~CAbstractMetaCommand() = default;

	void Execute() override;
	
};


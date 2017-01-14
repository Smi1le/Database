#pragma once
#include "ICommand.h"
#include "DataBaseLib.h"

class CAbstractCommand : public ICommand
{
public:
	CAbstractCommand(CDataBaseLib & lib);
	virtual ~CAbstractCommand() = default;

	void Execute() override;
protected:
	virtual void DoExecute(std::string const & inputStr) = 0;
	void SetDelimeter(std::string const & delimeter);

	std::string m_delimeter;
	CDataBaseLib m_lib;
};


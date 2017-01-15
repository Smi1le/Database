#pragma once
#include "AbstractMetaCommand.h"
#include "DataBaseLib.h"

class CCreateTableCommand : public CAbstractMetaCommand
{
public:
	CCreateTableCommand(CDataBaseLib & lib);

protected:
	void DoExecute(std::string const & inputStr) override;
	void Run() override;
private:
	std::string m_tableName;
	std::vector<Column> m_columns;
};


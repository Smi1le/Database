#include "stdafx.h"
#include "ShowTableCommand.h"


CShowTableCommand::CShowTableCommand(CDataBaseLib & lib)
	: CAbstractCommand(lib)
{
	SetDelimeter("-->");
}

void CShowTableCommand::DoExecute(std::string const & tableName)
{
	auto table = m_lib.GetTable(tableName);
	auto notesCount = table.GetNotesCount();
	auto columnCount = table.GetColumnCount();
	std::cout << "table name - " << table.GetName() << std::endl;
	for (size_t i = 0; i < notesCount; ++i)
	{
		auto note = table.GetNote(i);
		for (size_t j = 0; j < columnCount; ++j)
		{
			std::cout << note.GetColumnValue(j).GetValue() << " ";
		}
		std::cout << std::endl;
	}
}

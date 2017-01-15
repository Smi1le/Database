#include "stdafx.h"
#include "Application.h"
#include "Types.h"
#include <boost/range/algorithm/find_if.hpp>

#include "LoadTablesCommand.h"
#include "RemoveTableCommand.h"
#include "RenameTableCommand.h"



CApplication::CApplication()
{
	InitCommand();
}

void CApplication::Run()
{
	
	std::string command;
	while ((std::cout << ">")
		&& getline(std::cin, command))
	{
		try
		{
			ExecuteCommand(command);
		}
		catch (const std::exception& error)
		{
			std::cerr << "-------- ERROR!!! -------\n" <<
				error.what() << std::endl
				<< "-------------------------" << std::endl;
		}
	}
	
}

void CApplication::ExecuteCommand(const std::string & command)
{
	auto it = boost::find_if(m_commands, [&](const SCommand & item) {
		return item.shortcut == command;
	});
	if (it != m_commands.end())
		it->command->Execute();
	else
		std::cout << "Unknown command\n";
}

void CApplication::InitCommand()
{
	m_commands.emplace_back("loadTable", std::make_unique<CLoadTablesCommand>(m_lib));
	m_commands.emplace_back("remove", std::make_unique<CRemoveTableCommand>(m_lib));
	m_commands.emplace_back("rename", std::make_unique<CRenameTableCommand>(m_lib));
}

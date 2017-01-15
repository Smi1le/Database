#pragma once
#include <string>
#include "DataBaseLib.h"
#include "ICommand.h"


class CApplication
{
public:
	CApplication();
	
	void Run();
private:
	void ExecuteCommand(const std::string & command);
	void InitCommand();
private:
	CDataBaseLib m_lib;

	struct SCommand
	{
		SCommand(const std::string & shortcut,
			std::unique_ptr<ICommand> && command)
			: shortcut(shortcut)
			, command(std::move(command))
		{}

		std::string shortcut;
		std::unique_ptr<ICommand> command;
	};

	std::vector<SCommand> m_commands;
};


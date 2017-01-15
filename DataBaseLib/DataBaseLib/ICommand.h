#pragma once
#include <string>

class ICommand
{
public:
	virtual void Execute() = 0;
	virtual ~ICommand() = default;
};
#pragma once
#include "Command.h"

class IExecutableCommand : public Command
{
public:
	IExecutableCommand(SessionManager* const sesManager) : Command(sesManager) {};
};
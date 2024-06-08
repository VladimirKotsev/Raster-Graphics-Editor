#pragma once
#include "Command.h"

class IAddableCommand : public Command
{
public:
	IAddableCommand(SessionManager* const sesManager) : Command(sesManager) { };
};
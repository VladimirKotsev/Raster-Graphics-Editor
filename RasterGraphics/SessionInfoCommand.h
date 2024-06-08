#pragma once
#include "IExecutableCommand.h"

class SessionInfoCommand : public IExecutableCommand
{
public:
	SessionInfoCommand(SessionManager* const sesManager);
};


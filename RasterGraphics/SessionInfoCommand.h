#pragma once
#include "IExecutableCommand.h"

class SessionInfoCommand : public IExecutableCommand
{
public:
	SessionInfoCommand(SessionManager* const sesManager);

	// Inherited via IExecutableCommand
	void execute() const override;
};


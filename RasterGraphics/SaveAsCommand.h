#pragma once
#include "IExecutableCommand.h"
class SaveAsCommand : public IExecutableCommand
{
public:
	SaveAsCommand(SessionManager* const sesManager);

	// Inherited via IExecutableCommand
	void execute() const override;
};


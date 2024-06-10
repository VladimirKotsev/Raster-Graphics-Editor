#pragma once
#include "IExecutableCommand.h"

class SaveCommand : public IExecutableCommand
{
public:
	SaveCommand(SessionManager* const sesManager);

	// Inherited via IExecutableCommand
	void execute() const override;
};


#pragma once
#include "IExecutableCommand.h"
class UndoCommand : public IExecutableCommand
{
public:
	UndoCommand(SessionManager* const sesManager);

	// Inherited via IExecutableCommand
	void execute() const override;
};


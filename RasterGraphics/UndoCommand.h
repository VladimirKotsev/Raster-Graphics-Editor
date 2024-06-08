#pragma once
#include "IExecutableCommand.h"
class UndoCommand : public IExecutableCommand
{
public:
	UndoCommand(SessionManager* const sesManager);
};


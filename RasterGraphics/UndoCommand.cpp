#include "UndoCommand.h"

UndoCommand::UndoCommand(SessionManager* const sesManager) : IExecutableCommand(sesManager)
{
}

void UndoCommand::execute() const
{
	sessionManager->undo();
}

#include "SaveCommand.h"

SaveCommand::SaveCommand(SessionManager* const sesManager) : IExecutableCommand(sesManager)
{
}

void SaveCommand::execute() const
{
	sessionManager->saveSession();
}

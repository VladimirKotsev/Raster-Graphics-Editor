#include "SaveAsCommand.h"

SaveAsCommand::SaveAsCommand(SessionManager* const sesManager) : IExecutableCommand(sesManager)
{
}

void SaveAsCommand::execute() const
{
	sessionManager->saveAsSession();
}

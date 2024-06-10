#include "SessionInfoCommand.h"

SessionInfoCommand::SessionInfoCommand(SessionManager* const sesManager) : IExecutableCommand(sesManager)
{

}

void SessionInfoCommand::execute() const
{
	sessionManager->printSessionInfo();
}

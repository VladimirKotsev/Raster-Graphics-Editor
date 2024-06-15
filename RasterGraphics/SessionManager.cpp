#include "SessionManager.h"

SessionManager::SessionManager(Session* const session)
{
	container.addSession(session);
	currentSession = 1;
}

void SessionManager::createSession(Session* const session)
{
	container.addSession(session);
}

void SessionManager::undo()
{
	container[currentSession - 1]->undoTransformation();
}

void SessionManager::switchSession(unsigned sessionId)
{
	if (sessionId > container.getSize())
		throw std::invalid_argument("Invalid session id provided!");

	currentSession = sessionId;
}

void SessionManager::addCommandToSession(const Command& command)
{
	container[currentSession - 1]->addCommand(command);
}

void SessionManager::saveSession()
{
	container[currentSession - 1]->save();
}

void SessionManager::saveAsSession()
{
	container[currentSession - 1]->saveAs();
}

unsigned SessionManager::getCurrSession() const
{
	return currentSession;
}

void SessionManager::printSessionInfo() const
{
	//TO DO
}

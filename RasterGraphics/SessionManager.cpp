#include "SessionManager.h"
#include "Command.h"

SessionManager::SessionManager(Session& session)
{
	container.addSession(session);
	currentSession = 1;
}

void SessionManager::createSession(Session* const session)
{
	container.addSession(session);
}

void SessionManager::addImage(MyString filePath)
{
	container[currentSession - 1]->addImage(filePath);
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

void SessionManager::addCommand(const polymorphic_ptr<Command>& command)
{
	container[currentSession - 1]->addCommand(command);
}

void SessionManager::closeSession()
{
	container.removeAt(currentSession - 1);
}

void SessionManager::saveSession()
{
	container[currentSession - 1]->save();
}

void SessionManager::saveAsSession()
{
	container[currentSession - 1]->saveAs();
}

unsigned SessionManager::getCurrSessionID() const
{
	return currentSession;
}

const Session& SessionManager::getCurrentSession() const
{
	return *container[currentSession - 1];
}

void SessionManager::collage() {}

std::ostream& operator<<(std::ostream& os, const SessionManager& sm)
{
	os << "Session ID: " << sm.currentSession << '\n';
	os << "Images in session: " << sm.container[sm.currentSession - 1] << '\n';
	os << "Transformation in session: " /*TO DO CONTAINER*/;

	return os;
}

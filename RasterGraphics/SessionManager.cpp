#include "SessionManager.h"
#include "Command.h"

SessionManager::SessionManager(Session& session)
{
	container.addSession(session);
	currentSession = 1;
}

SessionManager::~SessionManager()
{

}

void SessionManager::createSession(Session* const session)
{
	container.addSession(session);
	currentSession = session->getID();
}

bool SessionManager::checkIfSessionOpened() const
{
	return (currentSession != 0);
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

void SessionManager::addCommand(Command* command)
{
	container[currentSession - 1]->addCommand(command);
}

void SessionManager::closeSession()
{
	container.removeAt(currentSession - 1);
	currentSession = 0;
}

void SessionManager::saveSession()
{
	container[currentSession - 1]->save();
}

void SessionManager::saveAsSession(const MyString& newFilePath)
{
	container[currentSession - 1]->saveAs(newFilePath);
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

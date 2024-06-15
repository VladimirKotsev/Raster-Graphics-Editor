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
	/*Name of images in the session : img1.ppm img2.pgm
		Pending transformations : rotate left, grayscale*/
	std::cout << "Session info: " << currentSession << std::endl;
	std::cout << "Images in session: ";

	size_t size = container[currentSession - 1]->getImages().getSize();
	for (size_t i = 0; i < size; i++)
	{
		std::cout << container[currentSession - 1]->getImages()[i]->getFilePath();

		if (i - 1 < size)
			std::cout << ", ";
	}
}

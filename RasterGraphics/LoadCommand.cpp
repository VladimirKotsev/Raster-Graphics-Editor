#include "LoadCommand.h"

LoadCommand::LoadCommand(SessionManager* const sesManager, MyString* images, size_t n) : 
	images(images), n(n), IExecutableCommand(sesManager)
{
}

void LoadCommand::execute() const
{
	//sessionManager->createSession(images, n);
}

Command* LoadCommand::clone() const
{
	Command* toReturn = new (std::nothrow) LoadCommand(*this);
	return toReturn;
}

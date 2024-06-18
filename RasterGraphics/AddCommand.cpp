#include "AddCommand.h"

AddCommand::AddCommand(SessionManager* const sesManager, MyString filePath) : IAddableCommand(sesManager, filePath)
{
}

void AddCommand::execute() const
{
	sessionManager->addImage(imagePath);
}

Command* AddCommand::clone() const
{
	Command* toReturn = new (std::nothrow) AddCommand(*this);
	return toReturn;
}

#include "AddCommand.h"
#include "SessionManager.h"

AddCommand::AddCommand(const MyString& filePath) : IAddableCommand(filePath)
{
}

Command* AddCommand::clone() const
{
	Command* toReturn = new (std::nothrow) AddCommand(*this);
	return toReturn;
}

void AddCommand::execute(SessionManager* sessionManager) const
{
	sessionManager->addImage(filePath);
}

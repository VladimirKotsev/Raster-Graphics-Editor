#include "AddCommand.h"

AddCommand::AddCommand(SessionManager* const sesManager, MyString* filePath) : IAddableCommand(sesManager, filePath)
{
}

Command* AddCommand::clone() const
{
	Command* toReturn = new (std::nothrow) AddCommand(*this);
	return toReturn;
}

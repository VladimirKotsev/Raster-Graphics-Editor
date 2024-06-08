#include "AddCommand.h"

AddCommand::AddCommand(SessionManager* const sesManager, MyString filePath) : IAddableCommand(sesManager, filePath)
{
}

void AddCommand::execute() const
{
	//add image to current session
}

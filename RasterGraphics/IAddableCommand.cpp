#include "IAddableCommand.h"

IAddableCommand::IAddableCommand(SessionManager* const sesManager, MyString filePath) : 
	imagePath(filePath), Command(sesManager)
{
}

const MyString& IAddableCommand::getImagePath() const
{
	return imagePath;
}
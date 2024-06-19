#include "IAddableCommand.h"

IAddableCommand::IAddableCommand(SessionManager* const sesManager, MyString* filePath) : 
	filePath(filePath), Command(sesManager)
{

}

void IAddableCommand::execute() const
{
	//sessionManager->addImage(image);
}

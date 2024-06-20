#include "AddCommand.h"
#include "Session.h"
#include "ImageFactory.h"

AddCommand::AddCommand(const MyString& filePath) : IAddableCommand(filePath)
{
}

Command* AddCommand::clone() const
{
	Command* toReturn = new (std::nothrow) AddCommand(*this);
	return toReturn;
}

void AddCommand::execute(Session* session) const
{
	Image* image = ImageFactory::createImage(filePath);
	session->addImage(image);
}

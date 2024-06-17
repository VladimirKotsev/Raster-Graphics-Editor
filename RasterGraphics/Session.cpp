#include "Session.h"
#include "ITransformableCommand.h"

unsigned Session::initializationCount = 0;

unsigned Session::getLastTransformationIndex() const
{
	size_t size = commands.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (ITransformableCommand* transf = dynamic_cast<ITransformableCommand*>(commands[i]));
	}
}

void Session::executeCommands()
{
	//unqueue the command and executes the transformations to each image
}

Session::Session()
{
	initializationCount++;
	ID = initializationCount;
}

Session* Session::clone() const
{
	Session* toReturn = new (std::nothrow) Session(*this);
	return toReturn;
}

void Session::addCommand(const Command& command)
{
	commands.pushBack(command);
}

void Session::undoTransformation()
{
	size_t atIndex = getLastTransformationIndex();

	if (atIndex == -1)
		return;

	commands.popAt(atIndex);
}

void Session::addImage(MyString filePath)
{
	addImage(filePath);
}

void Session::save()
{
	executeCommands(); //executes
}

void Session::saveAs()
{
	//executes command only for the first loaded image
}

unsigned Session::getID() const
{
	return ID;
}

const ImageContainer& Session::getImages() const
{
	return images;
}

const Vector<Command>& Session::getCommands() const
{
	return commands;
}

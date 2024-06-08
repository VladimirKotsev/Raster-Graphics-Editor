#include "Session.h"

unsigned Session::initializationCount = 0;

unsigned Session::getLastTransformationIndex() const
{
	for (unsigned i = commands.getSize(); i >= 0; i--)
	{
		switch (commands[i].getCommandType())
		{
		case CommandType::TRANSFORMATION: 
			return i;
		}
	}

	return -1;
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

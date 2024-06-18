#include "Session.h"
//#include "ITransformableCommand.h"

unsigned Session::initializationCount = 0;

int Session::getLastTransformationIndex() const
{
	size_t size = commands.getSize();
	for (int i = size - 1; i >= 0; i--)
	{
		/*if (const ITransformableCommand* transf = dynamic_cast<const ITransformableCommand*>(commands[i].operator->()))
			return i;*/
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

void Session::addCommand(Command* command)
{
	commands.pushBack(command);
}

void Session::undoTransformation()
{
	size_t atIndex = getLastTransformationIndex();

	if (atIndex == -1)
		return;

	int index = getLastTransformationIndex();

	if (index != -1)
		commands.popAt(index);
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


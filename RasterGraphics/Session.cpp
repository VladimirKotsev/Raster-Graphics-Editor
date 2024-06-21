#include "Session.h"
#include "ITransformableCommand.h"

unsigned Session::initializationCount = 0;

int Session::getLastTransformationIndex() const
{
	size_t size = commands.getSize();
	for (int i = size - 1; i >= 0; i--)
	{
		if (const ITransformableCommand* transf = dynamic_cast<const ITransformableCommand*>(commands[i]))
			return i;
	}

	return -1;
}

void Session::executeCommands()
{
	size_t commandCount = commands.getSize();
	for (size_t i = 0; i < commandCount; i++)
	{
		commands[i]->execute(this);
	}
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
	commands.addCommand(command);
}

void Session::undoTransformation()
{
	size_t atIndex = getLastTransformationIndex();

	if (atIndex == -1)
		return;

	int index = getLastTransformationIndex();

	if (index != -1)
		commands.removeAt(index);
}

void Session::addImage(Image* image)
{
	images.addImage(image);
}

void Session::negative()
{
	size_t imageCount = images.getSize();
	for (size_t i = 0; i < imageCount; i++)
	{
		if (!(images[i]->isLoaded()))
			images[i]->load();

		images[i]->negative();
	}

}

void Session::grayscale()
{
	size_t imageCount = images.getSize();
	for (size_t i = 0; i < imageCount; i++)
	{
		if (!(images[i]->isLoaded()))
			images[i]->load();

		if (images[i]->getIsGrayscale())
			continue;

		images[i]->grayscale();
	}
}

void Session::monochrome()
{
	size_t imageCount = images.getSize();
	for (size_t i = 0; i < imageCount; i++)
	{
		if (!(images[i]->isLoaded()))
			images[i]->load();

		if (images[i]->getIsMonochrome())
			continue;

		images[i]->monochrome();
	}
}

void Session::rotateLeft()
{
	size_t imageCount = images.getSize();
	for (size_t i = 0; i < imageCount; i++)
	{
		if (!(images[i]->isLoaded()))
			images[i]->load();

		images[i]->rotateLeft();
	}
}

void Session::rotateRight()
{
	size_t imageCount = images.getSize();
	for (size_t i = 0; i < imageCount; i++)
	{
		if (!(images[i]->isLoaded()))
			images[i]->load();

		images[i]->rotateRight();
	}
}

void Session::save()
{
	executeCommands(); //executes
	size_t imageCount = images.getSize();
	for (size_t i = 0; i < imageCount; i++)
	{
		if (!(images[i]->isLoaded()))
			continue;

		images[i]->save();
	}
	commands.empty();
}

void Session::saveAs(const MyString& newFilePath)
{
	commands[0]->execute(this);
	images[0]->load();

	for (size_t i = 0; i < commands.getSize(); i++)
	{
		commands[i]->execute(images[0]);
	}
	images[0]->saveAs(newFilePath.c_str());
}

unsigned Session::getID() const
{
	return ID;
}

std::ostream& operator<<(std::ostream& os, const Session& ses)
{
	size_t count = ses.images.getSize();
	for (size_t i = 0; i < count; i++)
	{
		os << ses.images[i]->getFilePath();
		if (i + 1 < count)
			os << ", ";
	}

	return os;
}

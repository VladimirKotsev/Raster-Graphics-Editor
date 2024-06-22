#include "Session.h"
#include "ITransformableCommand.h"
#include "ExceptionMessages.h"
#include "ImageFactory.h"
#include "IAddableCommand.h"

unsigned Session::liveCount = 0;

int Session::getLastTransformationIndex() const
{
	size_t size = commands.getSize();
	for (int i = size - 1; i >= 0; i--)
	{
		const ITransformableCommand* transf = dynamic_cast<const ITransformableCommand*>(commands[i]);
		if (transf != nullptr)
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
	liveCount++;
	ID = liveCount;
}

Session::~Session()
{
	liveCount--;
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

int Session::findImageIndexByName(const MyString& filePath) const
{
	for (int i = 0; i < images.getSize(); i++)
	{
		if (images[i]->getFilePath() == filePath)
			return i;
	}

	return -1;
}

void Session::collageImagesHorizontal(const MyString& file1, const MyString& file2, const MyString& outFilePath)
{
	int firstImageIndex = findImageIndexByName(file1);
	int secondImageIndex = findImageIndexByName(file2);

	if (firstImageIndex == -1 || secondImageIndex == -1)
		throw std::logic_error(ExceptionMessages::MISSING_IMAGES_FOR_COLLAGE);

	images[firstImageIndex]->load();
	images[secondImageIndex]->load();

	Image* collage = images[firstImageIndex]; // copy
	images[secondImageIndex]->collageWith(images[secondImageIndex], true); // horizonal => true;

	collage->changeFilePath(outFilePath.c_str());
	images.addImage(collage);
}

void Session::collageImagesVertical(const MyString& file1, const MyString& file2, const MyString& outFilePath)
{
	int firstImageIndex = findImageIndexByName(file1);
	int secondImageIndex = findImageIndexByName(file2);

	if (firstImageIndex == -1 || secondImageIndex == -1)
		throw std::logic_error(ExceptionMessages::MISSING_IMAGES_FOR_COLLAGE);

	images[firstImageIndex]->load();
	images[secondImageIndex]->load();

	Image* collage = images[firstImageIndex]; // copy
	collage->collageWith(images[secondImageIndex], false); // not horizonal => false

	collage->changeFilePath(outFilePath.c_str());
	images.addImage(collage);
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

	for (size_t i = 1; i < commands.getSize(); i++)
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
	size_t count = ses.commands.getSize();
	os << "Images in session: ";
	for (size_t i = 0; i < count; i++)
	{
		const IAddableCommand* addable = dynamic_cast<const IAddableCommand*>(ses.commands[i]);

		if (addable != nullptr)
		{
			os << addable->toString();

			if (i + 1 < count)
				os << ", ";
		}
	}
	os << '\n';
	os << "Transformation in session: ";
	for (size_t i = 0; i < count; i++)
	{
		const ITransformableCommand* transformable = dynamic_cast<const ITransformableCommand*>(ses.commands[i]);

		if (transformable != nullptr)
		{
			os << transformable->toString();

			if (i + 1 < count)
				os << ", ";
		}
	}

	return os;
}

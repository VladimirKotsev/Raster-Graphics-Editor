#pragma once

#include "MyString.h"
#include "ImageContainer.h"
#include "CommandContainer.h"

class Command;

class Session
{
private:
	static unsigned initializationCount;

	unsigned ID = 0;

	ImageContainer images;
	CommandContainer commands;

	int getLastTransformationIndex() const;
	void executeCommands();
public:
	Session();
	Session* clone() const;

	void addCommand(Command* command);
	void addImage(Image* image);

	void negative();
	void grayscale();
	void monochrome();
	void rotate(const MyString& direction);

	void undoTransformation();
	void save();
	void saveAs();

	friend std::ostream& operator<<(std::ostream& os, const Session& ses);

	unsigned getID() const;
};


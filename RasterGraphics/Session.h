#pragma once

#include "Vector.hpp"
#include "MyString.h"
#include "PolymorphicPtr.hpp"
#include "ImageContainer.h"

class Command;

class Session
{
private:
	static unsigned initializationCount;

	unsigned ID = 0;

	ImageContainer images;
	Vector<polymorphic_ptr<Command>> commands;

	int getLastTransformationIndex() const;
	void executeCommands();
public:
	Session();
	Session* clone() const;

	void addCommand(Command* command);

	void addImage(MyString filePath);
	void undoTransformation();
	void save();
	void saveAs();

	unsigned getID() const;
};


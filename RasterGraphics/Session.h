#pragma once
#include <iostream>

#include "ImageContainer.h"
#include "Vector.hpp"
#include "Command.h"

class Session
{
private:
	static unsigned initializationCount;

	unsigned ID = 0;

	//image container
	ImageContainer images;
	Vector<Command> commands;

	unsigned getLastTransformationIndex() const;
	void executeCommands();
public:
	Session();
	Session* clone() const;

	void addCommand(const Command& command);

	void addImage(MyString filePath);
	void undoTransformation();
	void save();
	void saveAs();

	unsigned getID() const;
	const ImageContainer& getImages() const;
	const Vector<Command>& getCommands() const;
};


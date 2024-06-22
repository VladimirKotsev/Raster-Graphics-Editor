#pragma warning(disable: 4996)
#include "RotateCommand.h"

RotateCommand::RotateCommand(Direction direction) : direction(direction)
{
}


Command* RotateCommand::clone() const
{
	Command* toReturn = new (std::nothrow) RotateCommand(*this);
	return toReturn;
}

void RotateCommand::execute(Session* session) const
{
	if (direction == Direction::right)
		session->rotateRight();
	else
		session->rotateLeft();
}

void RotateCommand::execute(Image* image) const
{
	if (direction == Direction::right)
		image->rotateRight();
	else
		image->rotateLeft();
}

MyString& RotateCommand::toString() const
{
	char str[GlobalConstants::BUFFER_SIZE] = "rotate";
	switch (direction)
	{
	case Direction::left: 
		strcat(str, " left");
		break;
	case Direction::right:
		strcat(str, " right");
		break;
	}

	MyString toReturn(str);
	return toReturn;
}

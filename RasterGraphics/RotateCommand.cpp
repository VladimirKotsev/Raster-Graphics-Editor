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

const char* RotateCommand::toString() const
{
	return (direction == Direction::left) ? "rotate left" : "rotate right";
}

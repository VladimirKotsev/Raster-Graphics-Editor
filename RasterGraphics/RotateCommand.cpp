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

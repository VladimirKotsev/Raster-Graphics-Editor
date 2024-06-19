#include "RotateCommand.h"
#include "SessionManager.h"

RotateCommand::RotateCommand(Direction direction) : direction(direction)
{
}


Command* RotateCommand::clone() const
{
	Command* toReturn = new (std::nothrow) RotateCommand(*this);
	return toReturn;
}

void RotateCommand::execute(SessionManager* sessionManager) const
{
	if (direction == Direction::right)
		sessionManager->rotateRight();
	else
		sessionManager->rotateLeft();
}

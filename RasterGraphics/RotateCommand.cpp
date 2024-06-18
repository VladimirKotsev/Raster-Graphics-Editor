#include "RotateCommand.h"

RotateCommand::RotateCommand(SessionManager* const sesManager, MyString direction) : 
	direction(direction), ITransformableCommand(sesManager)
{

}

const MyString& RotateCommand::getDirection() const
{
	return direction;
}

void RotateCommand::execute() const
{
}

Command* RotateCommand::clone() const
{
	Command* toReturn = new (std::nothrow) RotateCommand(*this);
	return toReturn;
}

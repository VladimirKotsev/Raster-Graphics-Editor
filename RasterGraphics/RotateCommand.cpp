#include "RotateCommand.h"

RotateCommand::RotateCommand(SessionManager* const sesManager, MyString direction) : 
	direction(direction), ITransformableCommand(sesManager)
{

}

const MyString& RotateCommand::getDirection() const
{
	return direction;
}

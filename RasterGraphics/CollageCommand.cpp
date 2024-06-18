#include "CollageCommand.h"

CollageCommand::CollageCommand(SessionManager* const sesManager, MyString filePath) : IAddableCommand(sesManager, filePath)
{
}

void CollageCommand::execute() const
{
}

Command* CollageCommand::clone() const
{
    Command* toReturn = new (std::nothrow) CollageCommand(*this);
    return toReturn;
}

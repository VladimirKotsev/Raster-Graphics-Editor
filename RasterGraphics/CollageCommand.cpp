#include "CollageCommand.h"

CollageCommand::CollageCommand(const MyString& firstFilePath, const MyString& secondFilePath, const MyString& outFilePath)
    : firstFilePath(firstFilePath), secondFilePath(secondFilePath), IAddableCommand(outFilePath)
{
}

Command* CollageCommand::clone() const
{
    Command* toReturn = new (std::nothrow) CollageCommand(*this);
    return toReturn;
}

void CollageCommand::execute() const
{
}

#include "CollageCommand.h"
#include "Session.h"
#include "ExceptionMessages.h"

CollageCommand::CollageCommand(Direction direction, const MyString& firstFilePath, const MyString& secondFilePath, const MyString& outFilePath)
    : direction(direction), firstFilePath(firstFilePath), secondFilePath(secondFilePath), IAddableCommand(outFilePath)
{

}

Command* CollageCommand::clone() const
{
    Command* toReturn = new (std::nothrow) CollageCommand(*this);
    return toReturn;
}

void CollageCommand::execute(Session* session) const
{
    switch (direction)
    {
    case CollageCommand::horizontal:
        session->collageImagesHorizontal(firstFilePath, secondFilePath, filePath);
        break;
    case CollageCommand::vertical:
        session->collageImagesHorizontal(firstFilePath, secondFilePath, filePath);
        break;
    }
}



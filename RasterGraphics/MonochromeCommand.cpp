#include "MonochromeCommand.h"

MonochromeCommand::MonochromeCommand(SessionManager* const sesManager) : ITransformableCommand(sesManager)
{
}

void MonochromeCommand::execute() const
{
}

Command* MonochromeCommand::clone() const
{
    Command* toReturn = new (std::nothrow) MonochromeCommand(*this);
    return toReturn;
}

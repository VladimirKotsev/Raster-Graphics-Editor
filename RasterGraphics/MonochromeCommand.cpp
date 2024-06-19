#include "MonochromeCommand.h"

void MonochromeCommand::execute() const
{
}

Command* MonochromeCommand::clone() const
{
    Command* toReturn = new (std::nothrow) MonochromeCommand(*this);
    return toReturn;
}

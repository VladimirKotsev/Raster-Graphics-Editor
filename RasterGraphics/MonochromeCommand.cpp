#include "MonochromeCommand.h"
#include "SessionManager.h"

Command* MonochromeCommand::clone() const
{
    Command* toReturn = new (std::nothrow) MonochromeCommand(*this);
    return toReturn;
}

void MonochromeCommand::execute(SessionManager* sessionManager) const
{
}

#include "GrayscaleCommand.h"
#include <iostream>

class SessionManager;

Command* GrayscaleCommand::clone() const
{
    Command* toReturn = new (std::nothrow) GrayscaleCommand(*this);
    return toReturn;
}

void GrayscaleCommand::execute(SessionManager* sessionManager) const
{
}
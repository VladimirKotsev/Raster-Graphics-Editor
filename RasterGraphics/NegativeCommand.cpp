#include "NegativeCommand.h"
#include "SessionManager.h"


Command* NegativeCommand::clone() const
{
    Command* toReturn = new (std::nothrow) NegativeCommand(*this);
    return toReturn;
}

void NegativeCommand::execute(SessionManager* sessionManager) const
{
}

#include "NegativeCommand.h"

Command* NegativeCommand::clone() const
{
    Command* toReturn = new (std::nothrow) NegativeCommand(*this);
    return toReturn;
}

void NegativeCommand::execute(Session* session) const
{
    session->negative();
}

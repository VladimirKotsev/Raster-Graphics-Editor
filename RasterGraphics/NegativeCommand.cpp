#include "NegativeCommand.h"

void NegativeCommand::execute() const
{
}

Command* NegativeCommand::clone() const
{
    Command* toReturn = new (std::nothrow) NegativeCommand(*this);
    return toReturn;
}

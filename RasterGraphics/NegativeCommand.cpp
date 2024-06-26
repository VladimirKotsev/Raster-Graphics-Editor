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

void NegativeCommand::execute(Image* image) const
{
    image->negative();
}

const char* NegativeCommand::toString() const
{
    return "negative";
}

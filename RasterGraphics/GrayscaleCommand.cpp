#include "GrayscaleCommand.h"

void GrayscaleCommand::execute() const
{
}

Command* GrayscaleCommand::clone() const
{
    Command* toReturn = new (std::nothrow) GrayscaleCommand(*this);
    return toReturn;
}

#include "GrayscaleCommand.h"

GrayscaleCommand::GrayscaleCommand(SessionManager* const sesManager) : ITransformableCommand(sesManager)
{
}

void GrayscaleCommand::execute() const
{
}

Command* GrayscaleCommand::clone() const
{
    Command* toReturn = new (std::nothrow) GrayscaleCommand(*this);
    return toReturn;
}

#include "GrayscaleCommand.h"

GrayscaleCommand::GrayscaleCommand(SessionManager* const sesManager) : ITransformableCommand(sesManager)
{
}

Command* GrayscaleCommand::clone() const
{
    Command* toReturn = new (std::nothrow) GrayscaleCommand(*this);
    return toReturn;
}

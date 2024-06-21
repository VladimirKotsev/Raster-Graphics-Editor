#include "GrayscaleCommand.h"
#include <iostream>

Command* GrayscaleCommand::clone() const
{
    Command* toReturn = new (std::nothrow) GrayscaleCommand(*this);
    return toReturn;
}

void GrayscaleCommand::execute(Session* session) const
{
    session->grayscale();
}

void GrayscaleCommand::execute(Image* image) const
{
    image->grayscale();
}

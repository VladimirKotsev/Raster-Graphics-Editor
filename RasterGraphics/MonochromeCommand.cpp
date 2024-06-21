#include "MonochromeCommand.h"

Command* MonochromeCommand::clone() const
{
    Command* toReturn = new (std::nothrow) MonochromeCommand(*this);
    return toReturn;
}

void MonochromeCommand::execute(Session* session) const
{
    session->monochrome();
}

void MonochromeCommand::execute(Image* image) const
{
    image->monochrome();
}

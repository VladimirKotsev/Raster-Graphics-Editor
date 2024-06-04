#include "Session.h"

unsigned Session::initializationCount = 0;

Session::Session()
{
    initializationCount++;
    ID = initializationCount;
}

Session* Session::clone() const
{
    Session* toReturn = new (std::nothrow) Session(*this);
    return toReturn;
}

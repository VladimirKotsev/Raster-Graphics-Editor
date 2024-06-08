#pragma once
#include "ITransformableCommand.h"
class RotateCommand :
    public ITransformableCommand
{
public:
    RotateCommand(SessionManager* const sesManager);
}


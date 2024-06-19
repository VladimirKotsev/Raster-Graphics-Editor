#pragma once

#include "ITransformableCommand.h"
#include "Command.h"
#include "MyString.h"

class RotateCommand : public ITransformableCommand
{
public:
    enum Direction
    {
        right,
        left
    };

private:
    Direction direction;
public:
    RotateCommand(Direction direction);

    Command* clone() const override;

    // Inherited via ITransformableCommand
    void execute(SessionManager* sessionManager) const override;
};

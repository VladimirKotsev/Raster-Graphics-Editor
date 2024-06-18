#pragma once

#include "ITransformableCommand.h"
#include "Command.h"
#include "MyString.h"

class RotateCommand : public ITransformableCommand
{
private:
    MyString direction;

public:
    RotateCommand(SessionManager* const sesManager, MyString direction);

    const MyString& getDirection() const;

    // Inherited via ITransformableCommand
    void execute() const override;
    Command* clone() const override;
};

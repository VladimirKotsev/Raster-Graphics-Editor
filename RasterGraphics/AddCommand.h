#pragma once
#include "IAddableCommand.h"
class AddCommand : public IAddableCommand
{
public:
 	AddCommand(SessionManager* const sesManager, MyString* filePath);

    // Inherited via IAddableCommand
    Command* clone() const override;

};


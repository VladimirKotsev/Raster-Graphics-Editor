#pragma once
#include "IAddableCommand.h"
class AddCommand : public IAddableCommand
{
public:
 	AddCommand(SessionManager* const sesManager);


    // Inherited via IAddableCommand
    void execute() const override;

};


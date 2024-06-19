#pragma once
#include "IAddableCommand.h"
class AddCommand : public IAddableCommand
{
public:
 	AddCommand(const MyString& filePath);

    // Inherited via IAddableCommand
    Command* clone() const override;


    // Inherited via IAddableCommand
    void execute(SessionManager* sessionManager) const override;

};


#pragma once

#include "Command.h"
#include "MyString.h"

class IAddableCommand : public Command
{
protected:
	MyString* filePath;
public:
	IAddableCommand(SessionManager* const sesManager, MyString* filePath);

	virtual ~IAddableCommand() = default;

	// Inherited via Command
	void execute() const override;
	Command* clone() const = 0;
};
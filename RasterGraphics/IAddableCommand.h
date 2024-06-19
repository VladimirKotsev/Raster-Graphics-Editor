#pragma once

#include "Command.h"
#include "MyString.h"

class IAddableCommand : public Command
{
protected:
	MyString filePath;
public:
	IAddableCommand(const MyString& filePath);

	virtual ~IAddableCommand() = default;

	// Inherited via Command
	Command* clone() const = 0;

	// Inherited via Command
	void execute(SessionManager* sessionManager) const = 0;
};
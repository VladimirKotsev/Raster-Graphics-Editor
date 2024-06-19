#pragma once

#include "Command.h"

class SessionManager;
class Command;

class ITransformableCommand : public Command
{
public:
	virtual ~ITransformableCommand() = default;

	// Inherited via Command
	void execute(SessionManager* sessionManager) const = 0;
	Command* clone() const override = 0;
};
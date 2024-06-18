#pragma once

#include "Command.h"

class SessionManager;
class Command;

class ITransformableCommand : public Command
{
public:
	ITransformableCommand(SessionManager* const sesManager) : Command(sesManager) {};

	virtual ~ITransformableCommand() = default;

	// Inherited via Command
	void execute() const override = 0;
	Command* clone() const override = 0;
};
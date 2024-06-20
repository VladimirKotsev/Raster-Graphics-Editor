#pragma once
#include "Command.h"
#include "Session.h"

//class Session;
class Command;

class ITransformableCommand : public Command
{
public:
	//virtual ~ITransformableCommand() = default;

	// Inherited via Command
	Command* clone() const = 0;
	virtual void execute(Session* session) const = 0;
};
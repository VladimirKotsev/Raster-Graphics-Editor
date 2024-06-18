#pragma once

#include "SessionManager.h"
class SessionManager;

class Command
{
protected:
	SessionManager* const sessionManager;

public:
	Command(SessionManager* const sesManager);

	virtual ~Command() = default;

	virtual void execute() const = 0;
	virtual Command* clone() const = 0;
};


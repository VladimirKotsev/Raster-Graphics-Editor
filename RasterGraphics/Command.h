#pragma once

//#include "SessionManager.h"
class SessionManager;

class Command
{
public:
	virtual ~Command() = default;

	virtual void execute(SessionManager* sessionManager) const = 0;
	virtual Command* clone() const = 0;
};


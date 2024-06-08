#pragma once
#include "SessionManager.h"

class Command
{
protected:
	SessionManager* const sessionManager;
public:
	Command(SessionManager* const sesManager);

	virtual void execute() const = 0;

};


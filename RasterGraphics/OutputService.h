#pragma once
#include "Session.h"

class OutputService
{
public:
	static void printSessionInfo(const Session& session);
	static void printSwitchedSession(unsigned id); //calls printSession
};


#pragma once
#include "IExecutableCommand.h"
class SwitchSessionCommand : public IExecutableCommand
{
public:
	SwitchSessionCommand(SessionManager* const sesManager);
};


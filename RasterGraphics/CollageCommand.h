#pragma once
#include "IAddableCommand.h"
class CollageCommand : public IAddableCommand
{
public:
	CollageCommand(SessionManager* const sesManager);
};


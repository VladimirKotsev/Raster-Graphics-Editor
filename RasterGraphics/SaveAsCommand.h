#pragma once
#include "IExecutableCommand.h"
class SaveAsCommand : public IExecutableCommand
{
public:
	SaveAsCommand(SessionManager* const sesManager);
};


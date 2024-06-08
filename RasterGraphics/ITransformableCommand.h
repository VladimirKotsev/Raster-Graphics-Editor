#pragma once
#include "Command.h"

class ITransformableCommand : public Command
{
public:
	ITransformableCommand(SessionManager* const sesManager) : Command(sesManager) {};
};
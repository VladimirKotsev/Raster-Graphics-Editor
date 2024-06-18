#pragma once

#include "Command.h"

class SessionManager;
class Command;

class ITransformableCommand : public Command
{
public:
	ITransformableCommand(SessionManager* const sesManager) : Command(sesManager) {};
};
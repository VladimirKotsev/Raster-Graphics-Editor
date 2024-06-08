#pragma once
#include "ITransformableCommand.h"

class MonochromeCommand : public ITransformableCommand
{
public:
	MonochromeCommand(SessionManager* const sesManager);
};


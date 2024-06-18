#pragma once
#include "ITransformableCommand.h"

class MonochromeCommand : public ITransformableCommand
{
public:
	MonochromeCommand(SessionManager* const sesManager);

	// Inherited via ITransformableCommand
	void execute() const override;
	Command* clone() const override;
};

